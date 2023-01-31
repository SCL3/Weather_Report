////////// CSV file creator //////////////////////////////////////////////////////

#include "head.h"

int descending_csv_Avl(FILE* output ,Avl* pAvl){
	if(pAvl != NULL){
		descending_csv_Avl(output, pAvl -> pRight);
		fprintf(output, "%d;%d;%lf;%lf\n", pAvl -> Meteo -> station, pAvl -> value, pAvl -> Meteo -> y, pAvl -> Meteo -> x);
		descending_csv_Avl(output, pAvl -> pLeft);
	}
	return 0;
}

int ascending_csv_Avl(FILE* output ,Avl* pAvl){
	if(pAvl != NULL){
		ascending_csv_Avl(output, pAvl -> pLeft);
		fprintf(output, "%d;%d;%lf;%lf\n", pAvl -> Meteo -> station, pAvl -> value, pAvl -> Meteo -> y, pAvl -> Meteo -> x);
		ascending_csv_Avl(output, pAvl -> pRight);
	}
	return 0;
}

int descending_csv_Abr(FILE* output ,Abr* pAbr){
	if(pAbr != NULL){
		descending_csv_Abr(output, pAbr -> pRight);
		fprintf(output, "%d;%d;%lf;%lf\n", pAbr -> Meteo -> station, pAbr -> value, pAbr -> Meteo -> y, pAbr -> Meteo -> x);
		descending_csv_Abr(output, pAbr -> pLeft);
	}
	return 0;
}

int ascending_csv_Abr(FILE* output ,Abr* pAbr){
	if(pAbr != NULL){
		ascending_csv_Abr(output, pAbr -> pLeft);
		fprintf(output, "%d;%d;%lf;%lf\n", pAbr -> Meteo -> station, pAbr -> value, pAbr -> Meteo -> y, pAbr -> Meteo -> x);
		ascending_csv_Abr(output, pAbr -> pRight);
	}
	return 0;
}

int csv_Node(FILE* output ,Node* pHead){
	if(pHead != NULL){
		fprintf(output, "%d;%d;%lf;%lf\n", pHead -> Meteo -> station, pHead -> value, pHead -> Meteo -> y, pHead -> Meteo -> x);
		csv_Node(output, pHead -> pNext);
	}
	return 0;
}
