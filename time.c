///////////// Function for the time //////////////////////////////////////////////

#include "head.h"

Time* createTime(){
	Time* pNew = malloc(sizeof(Time));
	if(pNew == NULL){  // Check if the malloc worked
		exit(4);
	}
	return pNew;
}

int time_calcul(Mto* meteo){  //convert the time format in hours
	return (meteo->Time->year*8760) + (meteo->Time->month*730) + (meteo->Time->day*24) + (meteo->Time->hour) + (meteo->Time->jet_lag);
}
