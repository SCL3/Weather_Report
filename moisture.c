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
	fprintf(output, "Station;Moisture;Latitude;Longitude\n");
	char row[50];
	char* station_c;  //Temporary char, used to store the char that will be transformed as an int or float
	char* moisture_c;
	char* y_c;  // North/South axis and East/West axis 
	char* x_c; 
	fgets(row, 50, input);  //remove the first line
	if(sort_mode == 0){  //Avl sort mode
		Avl* moisture_avl_tmp = NULL;  //Temporary avl tree (sorted by station)
		Avl* moisture_avl = NULL;
		while(fgets(row, 50, input) != NULL){  //while we are not in the end of a file	
			Mto* meteo = createMto();
			station_c = strtok(row, ";");
			moisture_c = strtok(NULL, ";");
			if(strchr(moisture_c, '.') != NULL){  //If the moisture case is empty (if it's empty, the value will take the coordinates !)
				meteo -> moisture = 0;
				y_c = strtok(moisture_c,",");
				x_c = strtok(NULL,";");
			}
			else{
				meteo -> moisture = atoi(moisture_c);
				y_c = strtok(NULL, ",");
			        x_c = strtok(NULL, ";");
			}
			meteo -> station = atoi(station_c);
			meteo -> y = atof(y_c); 
			meteo -> x = atof(x_c); 
			meteo -> value_sorted = 2;
			moisture_avl_tmp = insertAvl(moisture_avl_tmp, meteo -> station, meteo);  // Each station have their max moisture
		}
		recreateAvl(&moisture_avl, moisture_avl_tmp);
		if(ascending == 1){  //If the default mode is chosed, the moisture will be descending
			return descending_csv_Avl(output, moisture_avl);
		}
		else{
			return ascending_csv_Avl(output, moisture_avl);	
		}
	}
	else if(sort_mode == 1){  //Abr sort mode
		Abr* moisture_abr_tmp = NULL;  //Temporary abr tree (sorted by station)
		Abr* moisture_abr = NULL;
		while(fgets(row, 50, input) != NULL){  //while we are not in the end of a file
			Mto* meteo = createMto();
			station_c = strtok(row, ";");
			moisture_c = strtok(NULL, ";");
			if(strchr(moisture_c, '.') != NULL){  //If the moisture case is empty
				meteo -> moisture = 0;
				y_c = strtok(moisture_c,",");
				x_c = strtok(NULL,";");
			}
			else{
				meteo -> moisture = atoi(moisture_c);
				y_c = strtok(NULL, ",");
			        x_c = strtok(NULL, ";");
			}
			meteo -> station = atoi(station_c);
			meteo -> y = atof(y_c); 
			meteo -> x = atof(x_c); 
			meteo -> value_sorted = 2;
			moisture_abr_tmp = insertAbr(moisture_abr_tmp, meteo -> station, meteo);  // Each station have their max moisture
		}
		recreateAbr(&moisture_abr, moisture_abr_tmp);
		if(ascending == 1){  //If the default mode is chosed, the moisture will be descending
			return descending_csv_Abr(output, moisture_abr);
		}
		else{
			return ascending_csv_Abr(output, moisture_abr);	
		}
	}
	else{  //Node sort mode
		Node* moisture_node_tmp = NULL;  //Temporary node (sorted by station)
		Node* moisture_node = NULL;
		while(fgets(row, 50, input) != NULL){  //while we are not in the end of a file
			Mto* meteo = createMto();
			station_c = strtok(row, ";");
			moisture_c = strtok(NULL, ";");
			if(strchr(moisture_c, '.') != NULL){  //If the moisture case is empty
				meteo -> moisture = 0;
				y_c = strtok(moisture_c,",");
				x_c = strtok(NULL,";");
			}
			else{
				meteo -> moisture = atoi(moisture_c);
				y_c = strtok(NULL, ",");
			        x_c = strtok(NULL, ";");
			}
			meteo -> station = atoi(station_c);
			meteo -> y = atof(y_c); 
			meteo -> x = atof(x_c); 
			meteo -> value_sorted = 2;
			moisture_node_tmp = asc_insertNode(moisture_node_tmp, meteo -> station, meteo);  // Each station have their max moisture

		}
		if(ascending == 1){
			desc_recreateNode(&moisture_node, moisture_node_tmp);
		}
		else{
			asc_recreateNode(&moisture_node, moisture_node_tmp);
		}
		return csv_Node(output, moisture_node);
	}
}
