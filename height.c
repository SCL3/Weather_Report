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
		printf("error 3\n");
		exit(3);
	}
	printf("height, %s, %d, %d\n", output_fname, ascending, sort_mode);
	fprintf(output, "Station;Height;Latitude;Longitude\n");
	char row[50];
	char* station_c;  //Temporary char, used to store the char that will be transformed as an int or float
	char* height_c;
	char* y_c;  // North/South axis and East/West axis 
	char* x_c;  
	fgets(row, 50, input);  //remove the first line
	if(sort_mode == 0){  //Avl sort mode
		Avl* height_avl = NULL;
		while(fgets(row, 50, input) != NULL){  //while we are not in the end of a file  
			Mto* meteo = createMto();
			station_c = strtok(row, ";");
			y_c = strtok(NULL, ",");
			x_c = strtok(NULL, ";");
			height_c = strtok(NULL, ";");
				
			meteo -> station = atoi(station_c);  //Convert the value to put them in the meteo structure
			meteo -> height = atoi(height_c);
			meteo -> y = atof(y_c); 
			meteo -> x = atof(x_c); 
			meteo -> value_sorted = 1;
			height_avl = insertAvl(height_avl, meteo -> height, meteo);	
		}
		if(ascending == 1){  //If the default mode is chosed, the height will be descending
			return descending_csv_Avl(output, height_avl);
		}
		else{
			return ascending_csv_Avl(output, height_avl);	
		}
	}
	else if(sort_mode == 1){  //Abr sort mode
		Abr* height_abr = NULL;
		while(fgets(row, 50, input) != NULL){  //while we are not in the end of a file
			Mto* meteo = createMto();
			station_c = strtok(row, ";");
			y_c = strtok(NULL, ",");
			x_c = strtok(NULL, ";");
			height_c = strtok(NULL, ";");

			meteo -> station = atoi(station_c);  //Convert the value to put them in the meteo structure
			meteo -> height = atoi(height_c);
			meteo -> y = atof(y_c); 
			meteo -> x = atof(x_c); 
			meteo -> value_sorted = 1;
			height_abr = insertAbr(height_abr, meteo -> height, meteo);	
		}
		if(ascending == 1){  //If the default mode is chosed, the height will be descending
			return descending_csv_Abr(output, height_abr);
		}
		else{
			return ascending_csv_Abr(output, height_abr);	
		}
	}
	else{  //Node sort mode
		Node* height_node = NULL;
		while(fgets(row, 50, input) != NULL){  //while we are not in the end of a file
			Mto* meteo = createMto();
			station_c = strtok(row, ";");
			y_c = strtok(NULL, ",");
			x_c = strtok(NULL, ";");
			height_c = strtok(NULL, ";");

			meteo -> station = atoi(station_c);  //Convert the value to put them in the meteo structure
			meteo -> height = atoi(height_c);
			meteo -> y = atof(y_c); 
			meteo -> x = atof(x_c); 
			meteo -> value_sorted = 1;
			if(ascending == 1){  //If the default mode is chosed, the height will be descending
				height_node = desc_insertNode(height_node, meteo -> height, meteo);
			}
			else{
				height_node = asc_insertNode(height_node, meteo -> height, meteo);
			}
		}
		return csv_Node(output, height_node);
	}
}
