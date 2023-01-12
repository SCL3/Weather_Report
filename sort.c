#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avl.c"
#include "avl.h"

int height(char* output_fname, int ascending, int sort_mode){
	if(sort_mode == 0){
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
		Avl* height_avl;
		char* station_c;
		char* height_c;
		char* token;
		int station, height;
		fgets(row, 30, input);  //remove the first line
		while(fgets(row, 30, input) != NULL){  //while we are not in the end of a file
			token = strtok(row, ";");
			station_c = token;
			while(token != NULL){
				height_c = token;
				token = strtok(NULL, ";");
			}	
			station = atoi(station_c);
			height = atoi(height_c);
			height_avl = insertAvl(height_avl, height, station);	
		}
		infixeDecAvl_h(height_avl);
		if(ascending == 1){  //If the default mode is chosed, the height will be descending
			return descending_csv_h(output, height_avl);
		}
		else{
			return ascending_csv_h(output, height_avl);	
		}
	}
	else if(sort_mode == 1){
	
	}
	else{
	
	}
	return 0;
}

int main(int argc, char *argv[]){
	if(argc < 3){  //The program needs 2 more arguments input and output file
		printf("The program needs 2 more arguments (input and output files)\n");
		exit(4);
	}
	int ascending = 1;  //(default)
	int sort_mode = 0; //(default) avl = 0 ; abr = 1 ; tab = 2     
	// ./sort height.csv sorted.csv r avl
	for(int i = 3; i < argc; i++){
		if(strcmp(argv[i], "r") == 0){  //descending order asked ("strcmp" used to compare two string)
			ascending = 0;
		}
		else if(strcmp(argv[i], "abr") == 0){  //sort mode asked
			sort_mode = 1;
		}
		else if(strcmp(argv[i], "tab") == 0){  //sort mode asked
			sort_mode = 2;
		}
		else if(strcmp(argv[i], "avl") == 0){  //sort mode asked
			sort_mode = 0;
		}
		else{
			printf("The argument '%s' does not exist\n", argv[i]);
		}
	}
	if(strcmp(argv[1], "height.csv") == 0){
		height(argv[2], ascending, sort_mode);
	}
	return 0;
}
