////////// CSV file creator //////////////////////////////////////////////////////

#include "head.h"

int descending_csv_h(FILE* output ,Avl* pAvl){
	if(pAvl != NULL){
		descending_csv_h(output, pAvl -> pRight);
		fprintf(output, "%d;%d\n", pAvl -> Meteo -> station, pAvl -> value);
		descending_csv_h(output, pAvl -> pLeft);
	}
	return 0;
}

int ascending_csv_h(FILE* output ,Avl* pAvl){
	if(pAvl != NULL){
		ascending_csv_h(output, pAvl -> pLeft);
		fprintf(output, "%d;%d\n", pAvl -> Meteo -> station, pAvl -> value);
		ascending_csv_h(output, pAvl -> pRight);
	}
	return 0;
}
