//////// Main Function /////////////////////////////////////////////////////////

#include "head.h"

int main(int argc, char *argv[]){
	int error_value;
	if(argc < 3){  //The program needs 2 more arguments input and output file
		printf("The program needs 2 more arguments (input and output files)\n");
		exit(4);
	}
	int ascending = 1;  //(default)
	int sort_mode = 0; //(default) avl = 0 ; abr = 1 ; tab = 2     
	// ./sort height.csv sorted.csv r avl
	for(int i = 3; i < argc; i++){
		if(strcmp(argv[i], "1") == 0){
		}
		else if(strcmp(argv[i], "0") == 0){  //descending order asked ("strcmp" used to compare two string)
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
		error_value = height(argv[2], ascending, sort_mode);
	}
	if(strcmp(argv[1], "moisture.csv") == 0){
		error_value = moisture(argv[2], ascending, sort_mode);
	}
	if(strcmp(argv[1], "wind.csv") == 0){
		error_value = wind(argv[2], ascending, sort_mode);
	}
	if(strcmp(argv[1], "temperature1.csv") == 0){
		error_value = temperature1(argv[2], ascending, sort_mode);
	}
	if(strcmp(argv[1], "temperature2.csv") == 0){
		error_value = temperature2(argv[2], ascending, sort_mode);
	}
	if(strcmp(argv[1], "temperature3.csv") == 0){
		//error_value = temperature3(argv[2], ascending, sort_mode);
	}
	if(strcmp(argv[1], "pressure1.csv") == 0){
		error_value = pressure1(argv[2], ascending, sort_mode);
	}
	if(strcmp(argv[1], "pressure2.csv") == 0){
		//error_value = pressure2(argv[2], ascending, sort_mode);
	}
	if(strcmp(argv[1], "pressure3.csv") == 0){
		//error_value = pressure3(argv[2], ascending, sort_mode);
	}
	return error_value;
}
