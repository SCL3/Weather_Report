#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int height(char* output_fname, int ascending, int sort_mode){
	FILE* input;  //input data file
	input = fopen("height.csv","r");  //Open the input file (read)
	if(input == NULL){  //Check if the file exist
		printf("error 2\n");
		exit(2);
	}
	FILE* output;  //output data file
	output = fopen(output_fname, "w");  //Open the entry file (read)
	if(output == NULL){  //Check if the file exist
		printf("error 2\n");
		exit(2);
	}
	printf("height, %s, %d, %d\n", output_fname, ascending, sort_mode);
	return 0;
}

int main(int argc, char *argv[]){
	if(argc != 5){  //The program needs 4 more arguments (1st one is ./sort)
		printf("There are not 4 arguments");
		exit(4);
	}
	int ascending = 1;  //(default)
	int sort_mode = 0; //(default) avl = 0 ; abr = 1 ; tab = 2     
	// ./sort height.csv sorted.csv 0 avl
	if(strcmp(argv[3], "1") == 0){  //descending order asked
		ascending = 0;
	}
	if(strcmp(argv[4], "abr") == 0){  //sort mode asked
		sort_mode = 1;
	}
	if(strcmp(argv[4], "tab") == 0){  //sort mode asked
		sort_mode = 2;
	}
	if(strcmp(argv[1], "height.csv") == 0){
		printf("%s", argv[2]);
		height(argv[2], ascending, sort_mode);
	}
	return 0;
}
