////// Function to sort "Moisture" ///////////////////////////////////////////////////////////////////

#include "head.h"

int moisture(char* output_fname, int ascending, int sort_mode){
	FILE* input;  //input data file
	input = fopen("moisture.csv","r");  //Open the input file (read)
	if(input == NULL){  //Check if the file exist
		printf("error 2\n");
		exit(2);
	}
	FILE* output;  //output data file
	output = fopen(output_fname, "w");  //Open the output file (write)
	if(output == NULL){  //Check if the file exist
		printf("error 3\n");
		exit(3);
	}
	printf("moisture, %s, %d, %d\n", output_fname, ascending, sort_mode);
	fprintf(output, "Station;Moisture\n");
	char row[50];
	char* station_c;
	char* moisture_c;
	char* token;
	int station, moisture;
	fgets(row, 50, input);  //remove the first line
	
	if(sort_mode == 0){	
		Avl* moisture_avl_tmp = NULL;  //Temporary avl tree (sorted by station)
		Avl* moisture_avl = NULL;
		while(fgets(row, 50, input) != NULL){  //while we are not in the end of a file
			Mto* meteo = createMto();
			token = strtok(row, ";");
			station_c = token;
			while(token != NULL){
				moisture_c = token;
				token = strtok(NULL, ";");
			}	
			station = atoi(station_c);
			moisture = atoi(moisture_c);
			meteo -> station = station;
			meteo -> moisture = moisture;
			meteo -> value_sorted = 2;
			moisture_avl_tmp = insertAvl(moisture_avl_tmp, station, meteo);  // Each station have their max moisture
		}
		recreateAvl(&moisture_avl, moisture_avl_tmp);
		if(ascending == 1){  //If the default mode is chosed, the moisture will be descending
			return descending_csv_Avl(output, moisture_avl);
		}
		else{
			return ascending_csv_Avl(output, moisture_avl);	
		}
	}
	else if(sort_mode == 1){
		Abr* moisture_abr_tmp = NULL;  //Temporary abr tree (sorted by station)
		Abr* moisture_abr = NULL;
		while(fgets(row, 50, input) != NULL){  //while we are not in the end of a file
			Mto* meteo = createMto();
			token = strtok(row, ";");
			station_c = token;
			while(token != NULL){
				moisture_c = token;
				token = strtok(NULL, ";");
			}	
			station = atoi(station_c);
			moisture = atoi(moisture_c);
			meteo -> station = station;
			meteo -> moisture = moisture;
			meteo -> value_sorted = 2;
			moisture_abr_tmp = insertAbr(moisture_abr_tmp, station, meteo);  // Each station have their max moisture
		}
		recreateAbr(&moisture_abr, moisture_abr_tmp);
		if(ascending == 1){  //If the default mode is chosed, the moisture will be descending
			return descending_csv_Abr(output, moisture_abr);
		}
		else{
			return ascending_csv_Abr(output, moisture_abr);	
		}
	}
	else{
		printf("height (pas pour l'instant), %s, %d, %d\n", output_fname, ascending, sort_mode);
	}
	return 0;
}
