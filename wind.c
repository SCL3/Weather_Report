//////////// Wind Functions ////////////////////////////////////////

#include "head.h"

int wind(char* output_fname, int ascending, int sort_mode){
	FILE* input;  //input data file
	input = fopen("wind.csv","r");  //Open the input file (read)
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
	printf("wind, %s, %d, %d\n", output_fname, ascending, sort_mode);
	fprintf(output, "Station;Wind Direction; Wind Speed;Latitude;Longitude\n");
	char row[50];
	char* station_c;  //Temporary char, used to store the char that will be transformed as an int or float
	char* wind_direction_c;
	char* wind_speed_c;
	char* y_c;  // North/South axis and East/West axis 
	char* x_c; 
	fgets(row, 50, input);  //remove the first line
	if(sort_mode == 0){  //Avl sort mode
		fgets(row, 50, input);  //remove the rest ot the first line beceause it's long
		Avl* wind_avl = NULL;  
		while(fgets(row, 50, input) != NULL){  //while we are not in the end of a file	
			Mto* meteo = createMto();
			station_c = strtok(row, ";");
			wind_direction_c = strtok(NULL, ";");
			if(strchr(wind_direction_c, '.') != NULL){  //If the wind case is empty (if it's empty, the value will take the coordinates !)
				if(strchr(strchr(wind_direction_c, '.')+1, '.') != NULL){  //If the case wind speed is empty too
					meteo -> wind_direction = -1;
					meteo -> wind_speed = -1;
					y_c = strtok(wind_direction_c,",");
					x_c = strtok(NULL,";");
					meteo -> y = atof(y_c); 
			  		meteo -> x = atof(x_c); 
				}
				else{  //there is a speed, but no direction (strange)
					meteo -> wind_direction = -1;
					wind_speed_c = wind_direction_c;
					y_c = strtok(NULL,",");
					x_c = strtok(NULL,";");
					meteo -> wind_speed = atof(wind_speed_c);
				}
			}
			else{  
				wind_speed_c = strtok(NULL, ";");
				if(strchr(wind_speed_c, ',') != NULL){  // If there is no speed, but a wind direction (strange too)
					meteo -> wind_speed = -1;
					y_c = strtok(wind_speed_c,",");
					x_c = strtok(NULL,";");
					meteo -> wind_direction = atof(wind_direction_c);
				}
				else{  //If there is a wind speed and a direction
					y_c = strtok(NULL, ",");
			                x_c = strtok(NULL, ";");
			                meteo -> wind_direction = atof(wind_direction_c);
					meteo -> wind_speed = atof(wind_speed_c);
				}	
			}
			meteo -> station = atoi(station_c);	
			meteo -> y = atof(y_c); 
			meteo -> x = atof(x_c); 
			meteo -> value_sorted = 3;
			meteo -> counter_direction = 1;
			meteo -> counter_speed = 1;
			wind_avl = insertAvl(wind_avl, meteo -> station, meteo); 
		}
		wind_avl = averageAvl(wind_avl);
		if(ascending == 1){  //If the default mode is chosed, the wind station will be asccending
			return ascending_csv_Avl(output, wind_avl);
		}
		else{
			return descending_csv_Avl(output, wind_avl);	
		}
	}
	else if(sort_mode == 1){  //Abr sort mode
		fgets(row, 50, input);  //remove the rest ot the first line beceause it's long
		Abr* wind_abr = NULL;  
		
		while(fgets(row, 50, input) != NULL){  //while we are not in the end of a file	
			Mto* meteo = createMto();
			station_c = strtok(row, ";");
			wind_direction_c = strtok(NULL, ";");
			if(strchr(wind_direction_c, '.') != NULL){  //If the wind case is empty (if it's empty, the value will take the coordinates !)
				if(strchr(strchr(wind_direction_c, '.')+1, '.') != NULL){  //If the case wind speed is empty too
					meteo -> wind_direction = -1;
					meteo -> wind_speed = -1;
					y_c = strtok(wind_direction_c,",");
					x_c = strtok(NULL,";");
					meteo -> y = atof(y_c); 
			  		meteo -> x = atof(x_c); 
				}
				else{  //there is a speed, but no direction (strange)
					meteo -> wind_direction = -1;
					wind_speed_c = wind_direction_c;
					y_c = strtok(NULL,",");
					x_c = strtok(NULL,";");
					meteo -> wind_speed = atof(wind_speed_c);
				}
			}
			else{  
				wind_speed_c = strtok(NULL, ";");
				if(strchr(wind_speed_c, ',') != NULL){  // If there is no speed, but a wind direction (strange too)
					meteo -> wind_speed = -1;
					y_c = strtok(wind_speed_c,",");
					x_c = strtok(NULL,";");
					meteo -> wind_direction = atof(wind_direction_c);
				}
				else{  //If there is a wind speed and a direction
					y_c = strtok(NULL, ",");
			                x_c = strtok(NULL, ";");
			                meteo -> wind_direction = atof(wind_direction_c);
					meteo -> wind_speed = atof(wind_speed_c);
				}	
			}
			meteo -> station = atoi(station_c);	
			meteo -> y = atof(y_c); 
			meteo -> x = atof(x_c); 
			meteo -> value_sorted = 3;
			meteo -> counter_direction = 1;
			meteo -> counter_speed = 1;
			wind_abr = insertAbr(wind_abr, meteo -> station, meteo); 
		}
		wind_abr = averageAbr(wind_abr);
		if(ascending == 1){  //If the default mode is chosed, the wind station will be ascending
			return ascending_csv_Abr(output, wind_abr);
		}
		else{
			return descending_csv_Abr(output, wind_abr);	
		}
	}
	else{  //Node sort mode
		fgets(row, 50, input);  //remove the rest ot the first line beceause it's long
		Node* wind_node = NULL;  
		while(fgets(row, 50, input) != NULL){  //while we are not in the end of a file	
			Mto* meteo = createMto();
			station_c = strtok(row, ";");
			wind_direction_c = strtok(NULL, ";");
			if(strchr(wind_direction_c, '.') != NULL){  //If the wind case is empty (if it's empty, the value will take the coordinates !)
				if(strchr(strchr(wind_direction_c, '.')+1, '.') != NULL){  //If the case wind speed is empty too
					meteo -> wind_direction = -1;
					meteo -> wind_speed = -1;
					y_c = strtok(wind_direction_c,",");
					x_c = strtok(NULL,";");
					meteo -> y = atof(y_c); 
			  		meteo -> x = atof(x_c); 
				}
				else{  //there is a speed, but no direction (strange)
					meteo -> wind_direction = -1;
					wind_speed_c = wind_direction_c;
					y_c = strtok(NULL,",");
					x_c = strtok(NULL,";");
					meteo -> wind_speed = atof(wind_speed_c);
				}
			}
			else{  
				wind_speed_c = strtok(NULL, ";");
				if(strchr(wind_speed_c, ',') != NULL){  // If there is no speed, but a wind direction (strange too)
					meteo -> wind_speed = -1;
					y_c = strtok(wind_speed_c,",");
					x_c = strtok(NULL,";");
					meteo -> wind_direction = atof(wind_direction_c);
				}
				else{  //If there is a wind speed and a direction
					y_c = strtok(NULL, ",");
			                x_c = strtok(NULL, ";");
			                meteo -> wind_direction = atof(wind_direction_c);
					meteo -> wind_speed = atof(wind_speed_c);
				}	
			}
			meteo -> station = atoi(station_c);	
			meteo -> y = atof(y_c); 
			meteo -> x = atof(x_c); 
			meteo -> value_sorted = 3;
			meteo -> counter_direction = 1;
			meteo -> counter_speed = 1;
			if(ascending == 1){  //If the default mode is chosed, the wind station will be ascescending
				wind_node = asc_insertNode(wind_node, meteo -> station, meteo);
			}
			else{
				wind_node = desc_insertNode(wind_node, meteo -> station, meteo);
			}
		}
		wind_node = averageNode(wind_node);
		return csv_Node(output, wind_node);
	}
}
