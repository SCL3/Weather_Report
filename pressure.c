////// Function to sort Atmospheric Pressure ///////////////////////////////////////////////////////////////////

#include "head.h"

int pressure1(char* output_fname, int ascending, int sort_mode){
	FILE* input;  //input data file
	input = fopen("pressure1.csv","r");  //Open the input file (read)
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
	printf("atomspheric pressure1, %s, %d, %d\n", output_fname, ascending, sort_mode);
	fprintf(output, "Station;min Pression;max Pression;average Pression;Latitude;Longitude\n");
	char row[50];
	char* station_c;  //Temporary char, used to store the char that will be transformed as an int or float
	char* pressure_c;
	char* y_c;  // North/South axis and East/West axis 
	char* x_c;  
	fgets(row, 50, input);  //remove the first line
	if(sort_mode == 0){
		Avl* pressure_avl = NULL;
		while(fgets(row, 50, input) != NULL){  //while we are not in the end of a file  
			Mto* meteo = createMto();
			station_c = strtok(row, ";");
			pressure_c = strtok(NULL, ";");
			if(strchr(strchr(pressure_c, '.')+1, '.') != NULL){  //If the pressure case is empty (if it's empty, the value will take the coordinates !)
				meteo -> temp_or_pres = -9999;  //give the pressure an impossible value because there is no value
				y_c = strtok(pressure_c, ",");
				x_c = strtok(NULL, ";");	
			}
			else{
				meteo -> temp_or_pres = atof(pressure_c);
				y_c = strtok(NULL, ",");
				x_c = strtok(NULL, ";");	
			}	
			meteo -> station = atoi(station_c);  //Convert the value to put them in the meteo structure
			meteo -> min_value = meteo -> temp_or_pres;  //These value will be compared between the min/max value of his station
			meteo -> max_value = meteo -> temp_or_pres;
			meteo -> y = atof(y_c); 
			meteo -> x = atof(x_c); 
			meteo -> value_sorted = 4;
			meteo -> counter = 1; 
			pressure_avl = insertAvl(pressure_avl, meteo -> station, meteo);	
		}
		pressure_avl = averageAvl(pressure_avl);
		if(ascending == 1){  //If the default mode is chosed, the height will be descending
			return ascending_csv_Avl(output, pressure_avl);
		}
		else{
			return descending_csv_Avl(output, pressure_avl);	
		}
	}
	else if(sort_mode == 1){
		Abr* pressure_abr = NULL;
		while(fgets(row, 50, input) != NULL){  //while we are not in the end of a file  
			Mto* meteo = createMto();
			station_c = strtok(row, ";");
			pressure_c = strtok(NULL, ";");
			if(strchr(strchr(pressure_c, '.')+1, '.') != NULL){  //If the pressure case is empty (if it's empty, the value will take the coordinates !)
				meteo -> temp_or_pres = -9999;  //give the pressure an impossible value because there is no value
				y_c = strtok(pressure_c, ",");
				x_c = strtok(NULL, ";");	
			}
			else{
				meteo -> temp_or_pres = atof(pressure_c);
				y_c = strtok(NULL, ",");
				x_c = strtok(NULL, ";");	
			}	
			meteo -> station = atoi(station_c);  //Convert the value to put them in the meteo structure
			meteo -> min_value = meteo -> temp_or_pres;  //These value will be compared between the min/max value of his station
			meteo -> max_value = meteo -> temp_or_pres;
			meteo -> y = atof(y_c); 
			meteo -> x = atof(x_c); 
			meteo -> value_sorted = 4;
			meteo -> counter = 1; 
			pressure_abr = insertAbr(pressure_abr, meteo -> station, meteo);	
		}
		pressure_abr = averageAbr(pressure_abr);
		if(ascending == 1){  //If the default mode is chosed, the height will be descending
			return ascending_csv_Abr(output, pressure_abr);
		}
		else{
			return descending_csv_Abr(output, pressure_abr);	
		}
	}
	else{
		Node* pressure_node = NULL;  
		while(fgets(row, 50, input) != NULL){  //while we are not in the end of a file	
			Mto* meteo = createMto();
			station_c = strtok(row, ";");
			pressure_c = strtok(NULL, ";");
			if(strchr(strchr(pressure_c, '.')+1, '.') != NULL){  //If the pressure case is empty (if it's empty, the value will take the coordinates !)
				meteo -> temp_or_pres = -9999;  //give the pressure an impossible value because there is no value
				y_c = strtok(pressure_c, ",");
				x_c = strtok(NULL, ";");	
			}
			else{
				meteo -> temp_or_pres = atof(pressure_c);
				y_c = strtok(NULL, ",");
				x_c = strtok(NULL, ";");	
			}	
			meteo -> station = atoi(station_c);  //Convert the value to put them in the meteo structure
			meteo -> min_value = meteo -> temp_or_pres;  //These value will be compared between the min/max value of his station
			meteo -> max_value = meteo -> temp_or_pres;
			meteo -> y = atof(y_c); 
			meteo -> x = atof(x_c); 
			meteo -> value_sorted = 4;
			meteo -> counter = 1; 
			if(ascending == 1){  //If the default mode is chosed, the pressure station will be ascescending
				pressure_node = asc_insertNode(pressure_node, meteo -> station, meteo);
			}
			else{
				pressure_node = desc_insertNode(pressure_node, meteo -> station, meteo);
			}
		}
		pressure_node = averageNode(pressure_node);
		return csv_Node(output, pressure_node);
	}
}

int pressure2(char* output_fname, int ascending, int sort_mode){
	FILE* input;  //input data file
	input = fopen("pressure2.csv","r");  //Open the input file (read)
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
	printf("atomspheric pressure2, %s, %d, %d\n", output_fname, ascending, sort_mode);
	fprintf(output, "Time;average Pression\n");
	char row[55];  //Temporary char, used to store the char that will be transformed as an int or float
	char* pressure_c;
	char* time_c;
	fgets(row, 55, input);  //remove the first line
	if(sort_mode == 0){
		Avl* pressure_avl = NULL;
		while(fgets(row, 55, input) != NULL){  //while we are not in the end of a file  
			Mto* meteo = createMto();
			time_c = strtok(row, ";");
			pressure_c = strtok(NULL, ";");
			
			//Every station have a pressure, so it's useless to check (in this file)
				
			sscanf(time_c, "%d-%d-%dT%d:00:00+%d",&meteo->Time->year,&meteo->Time->month,&meteo->Time->day,&meteo->Time->hour,&meteo->Time->jet_lag);
			meteo -> Time -> value = time_calcul(meteo);  //convert the time format in hours
			meteo -> temp_or_pres = atof(pressure_c);
			
			if(strchr(pressure_c, '.') == NULL){  //If there is no pressure
				meteo -> temp_or_pres = -9999;  //give the pressure an impossible value, because there is no data
			}
			meteo -> counter = 1; 
			meteo -> value_sorted = 5;  //pressure2 data
			pressure_avl = insertAvl(pressure_avl, meteo -> Time -> value, meteo);	
		}
		pressure_avl = averageAvl(pressure_avl);
		if(ascending == 1){  //If the default mode is chosed, the height will be descending
			return ascending_csv_Avl(output, pressure_avl);
		}
		else{
			return descending_csv_Avl(output, pressure_avl);	
		}
	}
	else if(sort_mode == 1){
		Abr* pressure_abr = NULL;
		while(fgets(row, 55, input) != NULL){  //while we are not in the end of a file  
			Mto* meteo = createMto();
			time_c = strtok(row, ";");
			pressure_c = strtok(NULL, ";");
			
			//Every station have a pressure, so it's useless to check (in this file)
				
			sscanf(time_c, "%d-%d-%dT%d:00:00+%d",&meteo->Time->year,&meteo->Time->month,&meteo->Time->day,&meteo->Time->hour,&meteo->Time->jet_lag);
			meteo -> Time -> value = time_calcul(meteo);  //convert the time format in hours
			meteo -> temp_or_pres = atof(pressure_c);
			
			if(strchr(pressure_c, '.') == NULL){  //If there is no pressure
				meteo -> temp_or_pres = -9999;  //give the pressure an impossible value, because there is no data
			}
			meteo -> counter = 1; 
			meteo -> value_sorted = 5;  //pressure2 data
			pressure_abr = insertAbr(pressure_abr, meteo -> Time -> value, meteo);	
		}
		pressure_abr = averageAbr(pressure_abr);
		if(ascending == 1){  //If the default mode is chosed, the height will be descending
			return ascending_csv_Abr(output, pressure_abr);
		}
		else{
			return descending_csv_Abr(output, pressure_abr);	
		}
	}
	else{  //MORE THAN 10 MINUTES !!!
		printf("Good Luck waiting :)\n");
		Node* pressure_node = NULL;
		while(fgets(row, 55, input) != NULL){
			Mto* meteo = createMto();
			time_c = strtok(row, ";");
			pressure_c = strtok(NULL, ";");
			
			//Every station have a pressure, so it's useless to check (in this file)
				
			sscanf(time_c, "%d-%d-%dT%d:00:00+%d",&meteo->Time->year,&meteo->Time->month,&meteo->Time->day,&meteo->Time->hour,&meteo->Time->jet_lag);
			meteo -> Time -> value = time_calcul(meteo);  //convert the time format in hours
			meteo -> temp_or_pres = atof(pressure_c);
			if(strchr(pressure_c, '.') == NULL){  //If there is no pressure
				meteo -> temp_or_pres = -9999;  //give the pressure an impossible value, because there is no data
			}
			meteo -> counter = 1; 
			meteo -> value_sorted = 5;  //pressure2 data
			if(ascending == 1){  //If the default mode is chosed, the pressure time will be ascescending
				pressure_node = asc_insertNode(pressure_node, meteo -> Time -> value, meteo);
			}
			else{
				pressure_node = desc_insertNode(pressure_node, meteo -> Time -> value, meteo);
			}
		}
		pressure_node = averageNode(pressure_node);
		return csv_Node(output, pressure_node);
	}
}

