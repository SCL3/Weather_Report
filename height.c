////// Function to sort "Height" ///////////////////////////////////////////////////////////////////

#include "head.h"

int height(char* output_fname, int ascending, int sort_mode){
	FILE* input;  //input data file
	input = fopen("height.csv","r");  //Open the input file (read)
	if(input == NULL){  //Check if the file exist
		printf("error 2\n");
		exit(2);
	}
	FILE* output;  //output data file
	output = fopen(output_fname, "w");  //Open the output file (write)
	if(output == NULL){  //Check if the file exist
		printf("error 2\n");
		exit(2);
	}
	printf("height, %s, %d, %d\n", output_fname, ascending, sort_mode);
	fprintf(output, "Station;Height\n");
	char row[30];
	char* station_c;
	char* height_c;
	char* token;
	int station, height;
	fgets(row, 30, input);  //remove the first line
	
	if(sort_mode == 0){
		Avl* height_avl = NULL;
		while(fgets(row, 30, input) != NULL){  //while we are not in the end of a file
			Mto* meteo = createMto();
			token = strtok(row, ";");
			station_c = token;
			while(token != NULL){
				height_c = token;
				token = strtok(NULL, ";");
			}	
			station = atoi(station_c);
			height = atoi(height_c);
			meteo -> station = station;
			meteo -> value_sorted = 1;
			height_avl = insertAvl(height_avl, height, meteo);	
		}
		if(ascending == 1){  //If the default mode is chosed, the height will be descending
			return descending_csv_Avl(output, height_avl);
		}
		else{
			return ascending_csv_Avl(output, height_avl);	
		}
	}
	else if(sort_mode == 1){
		Abr* height_abr = NULL;
		while(fgets(row, 30, input) != NULL){  //while we are not in the end of a file
			Mto* meteo = createMto();
			token = strtok(row, ";");
			station_c = token;
			while(token != NULL){
				height_c = token;
				token = strtok(NULL, ";");
			}	
			station = atoi(station_c);
			height = atoi(height_c);
			meteo -> station = station;
			meteo -> value_sorted = 1;
			height_abr = insertAbr(height_abr, height, meteo);	
		}
		if(ascending == 1){  //If the default mode is chosed, the height will be descending
			return descending_csv_Abr(output, height_abr);
		}
		else{
			return ascending_csv_Abr(output, height_abr);	
		}
	}
	else{
		printf("height (pas pour l'instant), %s, %d, %d\n", output_fname, ascending, sort_mode);
	}
	return 0;
}
