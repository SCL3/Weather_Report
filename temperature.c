////// Function to sort Temperature ///////////////////////////////////////////////////////////////////

#include "head.h"

int temperature1(char* output_fname, int ascending, int sort_mode){
	FILE* input;  //input data file
	input = fopen("temperature1.csv","r");  //Open the input file (read)
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
	printf("temperature1, %s, %d, %d\n", output_fname, ascending, sort_mode);
	fprintf(output, "Station;min Temperature;max Temperature;average Temperature;Latitude;Longitude\n");
	char row[50];
	char* station_c;  //Temporary char, used to store the char that will be transformed as an int or float
	char* temperature_c;
	char* y_c;  // North/South axis and East/West axis 
	char* x_c;  
	fgets(row, 50, input);  //remove the first line
	if(sort_mode == 0){  //Avl sort mode
		Avl* temperature_avl = NULL;
		while(fgets(row, 50, input) != NULL){  //while we are not in the end of a file  
			Mto* meteo = createMto();
			station_c = strtok(row, ";");
			y_c = strtok(NULL, ",");
			x_c = strtok(NULL, ";");
			temperature_c = strtok(NULL, ";");
			meteo -> station= atoi(station_c);  //Convert the value to put them in the meteo structure
			meteo -> temp_or_pres = atof(temperature_c);
			meteo -> min_value = meteo -> temp_or_pres;  //These value will be compared between the min/max value of his station
			meteo -> max_value = meteo -> temp_or_pres; 
			meteo -> y = atof(y_c); 
			meteo -> x = atof(x_c);
			if(strchr(temperature_c, '.') == NULL){  //If there is no temperature
				meteo -> temp_or_pres = -9999;  //give the temperature an impossible value, because there is no data
			}
			meteo -> counter = 1; 
			meteo -> value_sorted = 4;  //Temperature data
			temperature_avl = insertAvl(temperature_avl, meteo -> station, meteo);
				
		}
		temperature_avl = averageAvl(temperature_avl);
		if(ascending == 1){  //If the default mode is chosed, the height will be descending
			return ascending_csv_Avl(output, temperature_avl);
		}
		else{
			return descending_csv_Avl(output, temperature_avl);	
		}
	}
	else if(sort_mode == 1){  //Abr sort mode
		Abr* temperature_abr = NULL;
		while(fgets(row, 50, input) != NULL){  //while we are not in the end of a file  
			Mto* meteo = createMto();
			station_c = strtok(row, ";");
			y_c = strtok(NULL, ",");
			x_c = strtok(NULL, ";");
			temperature_c = strtok(NULL, ";");
			meteo -> station= atoi(station_c);  //Convert the value to put them in the meteo structure
			meteo -> temp_or_pres = atof(temperature_c);
			meteo -> y = atof(y_c); 
			meteo -> x = atof(x_c);
			if(strchr(temperature_c, '.') == NULL){  //If there is no temperature
				meteo -> temp_or_pres = -9999;  //give the temperature an impossible value, because there is no data
			}
			meteo -> min_value = meteo -> temp_or_pres;  //These value will be compared between the min/max value of his station
			meteo -> max_value = meteo -> temp_or_pres; 
			meteo -> counter = 1; 
			meteo -> value_sorted = 4;  //Temperature data
			temperature_abr = insertAbr(temperature_abr, meteo -> station, meteo);
		}
		temperature_abr = averageAbr(temperature_abr);
		if(ascending == 1){  //If the default mode is chosed, the height will be descending
			return ascending_csv_Abr(output, temperature_abr);
		}
		else{
			return descending_csv_Abr(output, temperature_abr);	
		}
	}
	else{
		Node* temperature_node = NULL;  
		while(fgets(row, 50, input) != NULL){  //while we are not in the end of a file	
			Mto* meteo = createMto();
			station_c = strtok(row, ";");
			y_c = strtok(NULL, ",");
			x_c = strtok(NULL, ";");
			temperature_c = strtok(NULL, ";");
			meteo -> station = atoi(station_c);  //Convert the value to put them in the meteo structure
			meteo -> temp_or_pres = atof(temperature_c);
			meteo -> min_value = meteo -> temp_or_pres;  //These value will be compared between the min/max value of his station
			meteo -> max_value = meteo -> temp_or_pres; 
			meteo -> y = atof(y_c); 
			meteo -> x = atof(x_c);
			if(strchr(temperature_c, '.') == NULL){  //If there is no temperature
				meteo -> temp_or_pres = -9999;  //give the temperature an impossible value, because there is no data
			}
			meteo -> counter = 1; 
			meteo -> value_sorted = 4;  //Temperature data
			
			if(ascending == 1){  //If the default mode is chosed, the temperature station will be ascescending
				temperature_node = asc_insertNode(temperature_node, meteo -> station, meteo);
			}
			else{
				temperature_node = desc_insertNode(temperature_node, meteo -> station, meteo);
			}
		}
		temperature_node = averageNode(temperature_node);
		return csv_Node(output, temperature_node);
	}
}

int temperature2(char* output_fname, int ascending, int sort_mode){
	FILE* input;  //input data file
	input = fopen("temperature2.csv","r");  //Open the input file (read)
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
	printf("temperature2, %s, %d, %d\n", output_fname, ascending, sort_mode);
	fprintf(output, "Station;Time;average Temperature;Latitude;Longitude\n");
	char row[75];
	char* station_c;  //Temporary char, used to store the char that will be transformed as an int or float
	char* temperature_c;
	char* time_c;
	char* y_c;  // North/South axis and East/West axis 
	char* x_c;  
	fgets(row, 75, input);  //remove the first line
	if(sort_mode == 0){  //Avl sort mode
		Avl* temperature_avl = NULL;
		while(fgets(row, 75, input) != NULL){
			Mto* meteo = createMto();
			station_c = strtok(row, ";");
			time_c = strtok(NULL, ";");
			y_c = strtok(NULL, ",");
			x_c = strtok(NULL, ";");
			temperature_c = strtok(NULL, ";");
			if(temperature_c == NULL){  //Every station have a temperature, so it's useless to check (in this file)
				
			} 
		}
	}
	else if(sort_mode == 1){  //Abr sort mode
		
	}
	else{  //Tab sort mode
		
	}
}
