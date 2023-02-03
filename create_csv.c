////////// CSV file creator //////////////////////////////////////////////////////

#include "head.h"

//////////////// AVL ///////////////////////////////////////////////////////

int descending_csv_Avl(FILE* output ,Avl* pAvl){
	if(pAvl != NULL){
		if(pAvl -> Meteo -> value_sorted == 3){  //If the Avl is about wind 
			descending_csv_Avl(output, pAvl -> pRight);
			fprintf(output, "%d;%lf;%lf;%lf;%lf\n", pAvl -> Meteo -> station, pAvl -> Meteo -> wind_direction, pAvl -> Meteo -> wind_speed, pAvl -> Meteo -> y, pAvl -> Meteo -> x);
			descending_csv_Avl(output, pAvl -> pLeft);
		}
		else if(pAvl -> Meteo -> value_sorted == 4){  //If the Avl is about temperature (or pressure) sorted by stations
			descending_csv_Avl(output, pAvl -> pRight);
			fprintf(output, "%d;%lf;%lf;%lf;%lf;%lf\n", pAvl -> Meteo -> station, pAvl -> Meteo -> min_value, pAvl -> Meteo -> max_value, pAvl -> Meteo -> temp_or_pres, pAvl -> Meteo -> y, pAvl -> Meteo -> x);
			descending_csv_Avl(output, pAvl -> pLeft);
		}
		else if(pAvl -> Meteo -> value_sorted == 5){  //If the Avl is about temperature (or pressure) sorted by times
			descending_csv_Avl(output, pAvl -> pRight);
			fprintf(output, "%d-%d-%dT%d:00:00+%d:00;%lf\n", pAvl->Meteo->Time->year,pAvl->Meteo->Time->month,pAvl->Meteo->Time->day, pAvl->Meteo->Time->hour, pAvl->Meteo->Time->jet_lag, pAvl -> Meteo -> temp_or_pres);
			descending_csv_Avl(output, pAvl -> pLeft);
		}
		else if(pAvl -> Meteo -> value_sorted == 6){  //If the Avl is about temperature (or pressure) sorted by times
			descending_csv_Avl(output, pAvl -> pRight);
			fprintf(output, "%d;%d-%d-%dT%d:00:00+%d:00;%lf\n",pAvl -> Meteo -> station, pAvl->Meteo->Time->year,pAvl->Meteo->Time->month,pAvl->Meteo->Time->day, pAvl->Meteo->Time->hour, pAvl->Meteo->Time->jet_lag, pAvl -> Meteo -> temp_or_pres);
			descending_csv_Avl(output, pAvl -> pLeft);
		}
		else{
			descending_csv_Avl(output, pAvl -> pRight);
			fprintf(output, "%d;%d;%lf;%lf\n", pAvl -> Meteo -> station, pAvl -> value, pAvl -> Meteo -> y, pAvl -> Meteo -> x);
			descending_csv_Avl(output, pAvl -> pLeft);
		}
	}
	return 0;
}

int ascending_csv_Avl(FILE* output ,Avl* pAvl){
	if(pAvl != NULL){
		if(pAvl -> Meteo -> value_sorted == 3){  //If the Avl is about wind 
			ascending_csv_Avl(output, pAvl -> pLeft);
			fprintf(output, "%d;%lf;%lf;%lf;%lf\n", pAvl -> Meteo -> station, pAvl -> Meteo -> wind_direction, pAvl -> Meteo -> wind_speed, pAvl -> Meteo -> y, pAvl -> Meteo -> x);
			ascending_csv_Avl(output, pAvl -> pRight);
		}
		else if(pAvl -> Meteo -> value_sorted == 4){  //If the Avl is about temperature (or pressure) sorted by stations
			ascending_csv_Avl(output, pAvl -> pLeft);
			fprintf(output, "%d;%lf;%lf;%lf;%lf;%lf\n", pAvl -> Meteo -> station, pAvl -> Meteo -> min_value, pAvl -> Meteo -> max_value, pAvl -> Meteo -> temp_or_pres, pAvl -> Meteo -> y, pAvl -> Meteo -> x);
			ascending_csv_Avl(output, pAvl -> pRight);
		}
		else if(pAvl -> Meteo -> value_sorted == 5){  //If the Avl is about temperature (or pressure) sorted by times
			ascending_csv_Avl(output, pAvl -> pLeft);
			fprintf(output, "%d-%d-%dT%d:00:00+%d:00;%lf\n", pAvl->Meteo->Time->year,pAvl->Meteo->Time->month,pAvl->Meteo->Time->day, pAvl->Meteo->Time->hour, pAvl->Meteo->Time->jet_lag, pAvl -> Meteo -> temp_or_pres);
			ascending_csv_Avl(output, pAvl -> pRight);
		}
		else if(pAvl -> Meteo -> value_sorted == 7){  //If the Avl is about temperature (or pressure) sorted by times
			ascending_csv_Avl(output, pAvl -> pLeft);
			fprintf(output, "%d;%d-%d-%dT%d:00:00+%d:00;%lf\n", pAvl -> Meteo -> station, pAvl->Meteo->Time->year,pAvl->Meteo->Time->month,pAvl->Meteo->Time->day, pAvl->Meteo->Time->hour, pAvl->Meteo->Time->jet_lag, pAvl -> Meteo -> temp_or_pres);
			ascending_csv_Avl(output, pAvl -> pRight);
		}
		else{
			ascending_csv_Avl(output, pAvl -> pLeft);
			fprintf(output, "%d;%d;%lf;%lf\n", pAvl -> Meteo -> station, pAvl -> value, pAvl -> Meteo -> y, pAvl -> Meteo -> x);
			ascending_csv_Avl(output, pAvl -> pRight);
		}
	}
	return 0;
}

//////////////// ABR ///////////////////////////////////////////////////////

int descending_csv_Abr(FILE* output ,Abr* pAbr){
	if(pAbr != NULL){
		if(pAbr -> Meteo -> value_sorted == 3){  //If the Abr is about wind 
			descending_csv_Abr(output, pAbr -> pRight);
			fprintf(output, "%d;%lf;%lf;%lf;%lf\n", pAbr -> Meteo -> station, pAbr -> Meteo -> wind_direction, pAbr -> Meteo -> wind_speed, pAbr -> Meteo -> y, pAbr -> Meteo -> x);
			descending_csv_Abr(output, pAbr -> pLeft);
		}
		else if(pAbr -> Meteo -> value_sorted == 4){  //If the Abr is about temperature (or pressure) sorted by stations
			descending_csv_Abr(output, pAbr -> pRight);
			fprintf(output, "%d;%lf;%lf;%lf;%lf;%lf\n", pAbr -> Meteo -> station, pAbr -> Meteo -> min_value, pAbr -> Meteo -> max_value, pAbr -> Meteo -> temp_or_pres, pAbr -> Meteo -> y, pAbr -> Meteo -> x);
			descending_csv_Abr(output, pAbr -> pLeft);
		}
		else if(pAbr -> Meteo -> value_sorted == 5){  //If the Abr is about temperature (or pressure) sorted by times
			descending_csv_Abr(output, pAbr -> pRight);
			fprintf(output, "%d-%d-%dT%d:00:00+%d:00;%lf\n", pAbr->Meteo->Time->year,pAbr->Meteo->Time->month,pAbr->Meteo->Time->day, pAbr->Meteo->Time->hour, pAbr->Meteo->Time->jet_lag, pAbr -> Meteo -> temp_or_pres);
			descending_csv_Abr(output, pAbr -> pLeft);
		}
		else if(pAbr -> Meteo -> value_sorted == 6){  //If the Abr is about temperature (or pressure) sorted by times
			descending_csv_Abr(output, pAbr -> pRight);
			fprintf(output, "%d;%d-%d-%dT%d:00:00+%d:00;%lf\n", pAbr -> Meteo -> station, pAbr->Meteo->Time->year,pAbr->Meteo->Time->month,pAbr->Meteo->Time->day, pAbr->Meteo->Time->hour, pAbr->Meteo->Time->jet_lag, pAbr -> Meteo -> temp_or_pres);
			descending_csv_Abr(output, pAbr -> pLeft);
		}
		else{
			descending_csv_Abr(output, pAbr -> pRight);
			fprintf(output, "%d;%d;%lf;%lf\n", pAbr -> Meteo -> station, pAbr -> value, pAbr -> Meteo -> y, pAbr -> Meteo -> x);
			descending_csv_Abr(output, pAbr -> pLeft);
		}
	}
	return 0;
}

int ascending_csv_Abr(FILE* output ,Abr* pAbr){
	if(pAbr != NULL){
		if(pAbr -> Meteo -> value_sorted == 3){  //If the Abr is about wind 
			ascending_csv_Abr(output, pAbr -> pLeft);
			fprintf(output, "%d;%lf;%lf;%lf;%lf\n", pAbr -> Meteo -> station, pAbr -> Meteo -> wind_direction, pAbr -> Meteo -> wind_speed, pAbr -> Meteo -> y, pAbr -> Meteo -> x);
			ascending_csv_Abr(output, pAbr -> pRight);
		}
		else if(pAbr -> Meteo -> value_sorted == 4){  //If the Abr is about temperature (or pressure) sorted by stations
			ascending_csv_Abr(output, pAbr -> pLeft);
			fprintf(output, "%d;%lf;%lf;%lf;%lf;%lf\n", pAbr -> Meteo -> station, pAbr -> Meteo -> min_value, pAbr -> Meteo -> max_value, pAbr -> Meteo -> temp_or_pres, pAbr -> Meteo -> y, pAbr -> Meteo -> x);
			ascending_csv_Abr(output, pAbr -> pRight);
		}
		else if(pAbr -> Meteo -> value_sorted == 5){  //If the Abr is about temperature (or pressure) sorted by times
			ascending_csv_Abr(output, pAbr -> pLeft);
			fprintf(output, "%d-%d-%dT%d:00:00+%d:00;%lf\n", pAbr->Meteo->Time->year,pAbr->Meteo->Time->month,pAbr->Meteo->Time->day, pAbr->Meteo->Time->hour, pAbr->Meteo->Time->jet_lag, pAbr -> Meteo -> temp_or_pres);
			ascending_csv_Abr(output, pAbr -> pRight);
		}
		else if(pAbr -> Meteo -> value_sorted == 6){  //If the Abr is about temperature (or pressure) sorted by times
			ascending_csv_Abr(output, pAbr -> pLeft);
			fprintf(output, "%d;%d-%d-%dT%d:00:00+%d:00;%lf\n", pAbr -> Meteo -> station, pAbr->Meteo->Time->year,pAbr->Meteo->Time->month,pAbr->Meteo->Time->day, pAbr->Meteo->Time->hour, pAbr->Meteo->Time->jet_lag, pAbr -> Meteo -> temp_or_pres);
			ascending_csv_Abr(output, pAbr -> pRight);
		}
		else{
			ascending_csv_Abr(output, pAbr -> pLeft);
			fprintf(output, "%d;%d;%lf;%lf\n", pAbr -> Meteo -> station, pAbr -> value, pAbr -> Meteo -> y, pAbr -> Meteo -> x);
			ascending_csv_Abr(output, pAbr -> pRight);
		}
	}
	return 0;
}

//////////////// NODE (tab) ///////////////////////////////////////////////////////

int csv_Node(FILE* output ,Node* pHead){
	if(pHead != NULL){
		if(pHead -> Meteo -> value_sorted == 3){  //If the Node is about wind 
			fprintf(output, "%d;%lf;%lf;%lf;%lf\n", pHead -> Meteo -> station, pHead -> Meteo -> wind_direction, pHead -> Meteo -> wind_speed, pHead -> Meteo -> y, pHead -> Meteo -> x);
			csv_Node(output, pHead -> pNext);
		}
		else if(pHead -> Meteo -> value_sorted == 4){  //If the Node is about temperature (or pressure) sorted by stations
			fprintf(output, "%d;%lf;%lf;%lf;%lf;%lf\n", pHead -> Meteo -> station, pHead -> Meteo -> min_value, pHead -> Meteo -> max_value, pHead -> Meteo -> temp_or_pres, pHead -> Meteo -> y, pHead -> Meteo -> x);
			csv_Node(output, pHead -> pNext);
		}
		else if(pHead -> Meteo -> value_sorted == 5){  //If the Node is about temperature (or pressure) sorted by times
			fprintf(output, "%d-%d-%dT%d:00:00+%d:00;%lf\n", pHead->Meteo->Time->year,pHead->Meteo->Time->month,pHead->Meteo->Time->day, pHead->Meteo->Time->hour, pHead->Meteo->Time->jet_lag, pHead -> Meteo -> temp_or_pres);
			csv_Node(output, pHead -> pNext);
		}
		else if(pHead -> Meteo -> value_sorted == 6){  //If the Node is about temperature (or pressure) sorted by times
			fprintf(output, "%d;%d-%d-%dT%d:00:00+%d:00;%lf\n", pHead -> Meteo -> station, pHead->Meteo->Time->year,pHead->Meteo->Time->month,pHead->Meteo->Time->day, pHead->Meteo->Time->hour, pHead->Meteo->Time->jet_lag, pHead -> Meteo -> temp_or_pres);
			csv_Node(output, pHead -> pNext);
		}
		else{
			fprintf(output, "%d;%d;%lf;%lf\n", pHead -> Meteo -> station, pHead -> value, pHead -> Meteo -> y, pHead -> Meteo -> x);
			csv_Node(output, pHead -> pNext);
		}
	}
	return 0;
}

