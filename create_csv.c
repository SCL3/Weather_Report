////////// CSV file creator //////////////////////////////////////////////////////

#include "head.h"

int descending_csv_Avl(FILE* output ,Avl* pAvl){
	if(pAvl != NULL){
		descending_csv_Avl(output, pAvl -> pRight);
		fprintf(output, "%d;%d\n", pAvl -> Meteo -> station, pAvl -> value);
		descending_csv_Avl(output, pAvl -> pLeft);
	}
	return 0;
}

int ascending_csv_Avl(FILE* output ,Avl* pAvl){
	if(pAvl != NULL){
		ascending_csv_Avl(output, pAvl -> pLeft);
		fprintf(output, "%d;%d\n", pAvl -> Meteo -> station, pAvl -> value);
		ascending_csv_Avl(output, pAvl -> pRight);
	}
	return 0;
}

int descending_csv_Abr(FILE* output ,Abr* pAbr){
	if(pAbr != NULL){
		descending_csv_Abr(output, pAbr -> pRight);
		fprintf(output, "%d;%d\n", pAbr -> Meteo -> station, pAbr -> value);
		descending_csv_Abr(output, pAbr -> pLeft);
	}
	return 0;
}

int ascending_csv_Abr(FILE* output ,Abr* pAbr){
	if(pAbr != NULL){
		ascending_csv_Abr(output, pAbr -> pLeft);
		fprintf(output, "%d;%d\n", pAbr -> Meteo -> station, pAbr -> value);
		ascending_csv_Abr(output, pAbr -> pRight);
	}
	return 0;
}
