/////// ABR Functions ///////////////////////////////////////

#include "head.h"

Abr* createAbr(int val, Mto* meteo){
	Abr* pNew = malloc(sizeof(Abr));
	if(pNew == NULL){  // Check if the malloc worked
		exit(4);
	}
	pNew -> value = val;
	pNew -> Meteo = meteo;
	pNew -> pLeft = NULL;
	pNew -> pRight = NULL;
	return pNew;
}

void infixeAbr_h(Abr* pTree){  //ascending order
    if(pTree != NULL){
        infixeAbr_h(pTree -> pLeft);
        printf("val : %d \n", pTree -> value);
        infixeAbr_h(pTree -> pRight);
    }
}

void infixeDecAbr_h(Abr* pTree){  //descending order
    if(pTree != NULL){
        infixeDecAbr_h(pTree -> pRight);
        printf("altitude : %d et station : %d\n", pTree -> value, pTree -> Meteo -> height);
        infixeDecAbr_h(pTree -> pLeft);
    }
}

int Abr_check(Abr* pTree){
	if(pTree != NULL){
		int a = pTree -> value;
		if(pTree -> pLeft -> value >= a){
			return 0;
		}
		if(pTree -> pRight -> value <= a){
			return 0;
		}
		return Abr_check(pTree -> pLeft) + Abr_check(pTree -> pRight);	
	}
	return 1;
}

int search(Abr* pTree, int a){
    if(pTree == NULL) {
        return 0;
    }
    if(pTree -> value == a){
        return 1;
    }
    if(a < pTree -> value){
        return search(pTree -> pLeft, a);
    }
    else {
        return search(pTree->pRight, a);
    }
}

Abr* insertAbr(Abr* pAbr, int val, Mto* meteo){  //insert a new value in the abr
    if(pAbr == NULL){
        return createAbr(val, meteo);
    }
    else if(val < pAbr -> value){
        pAbr -> pLeft = insertAbr(pAbr -> pLeft, val, meteo);
    }
    else if(val > pAbr -> value){
        pAbr -> pRight = insertAbr(pAbr -> pRight, val, meteo);
    }
    else{  //if the value already exist 
    	if(meteo -> value_sorted == 1){  //Sort mode for the Height
		if (meteo -> station < pAbr -> Meteo -> station){
			pAbr -> pLeft = insertAbr(pAbr -> pLeft, val, meteo);
		}
		else if(meteo -> station > pAbr -> Meteo -> station){
			pAbr -> pRight = insertAbr(pAbr -> pRight, val, meteo);
		}
		else{
			return pAbr;  // If the value and the station is the same
		}
	}
	if(meteo -> value_sorted == 2){  //Sort mode for the Moisture
		if(meteo -> moisture > pAbr -> Meteo -> moisture){  //Replace the lowest moisture value with the highest 
			pAbr -> Meteo -> moisture = meteo -> moisture;
		}
	}
	else if(meteo -> value_sorted == 3){  //Sort mode for the Wind
			if(meteo -> wind_direction == -1 && meteo -> wind_speed == -1){  //If there is no data in the wind slot
				return pAbr;
			}
			else if(meteo -> wind_direction == -1){  //If there is only speed
				pAbr -> Meteo -> wind_speed += meteo -> wind_speed;
				pAbr -> Meteo -> counter_speed += 1; 
				return pAbr;
			}
			else if(meteo -> wind_speed == -1){  //If there is only direction
				pAbr -> Meteo -> wind_direction += meteo -> wind_direction;
				pAbr -> Meteo -> counter_direction += 1; 
				return pAbr;
			}
			pAbr -> Meteo -> wind_direction += meteo -> wind_direction;  //Add the speed and the direction, to make a total 
			pAbr -> Meteo -> wind_speed += meteo -> wind_speed;
			pAbr -> Meteo -> counter_direction += 1; 
			pAbr -> Meteo -> counter_speed += 1; 
			return pAbr;
		}
    }
    return pAbr;
}

Abr* averageAbr(Abr* pAbr){
	if(pAbr != NULL){
		pAbr -> Meteo -> wind_direction /= pAbr -> Meteo -> counter_direction;
		pAbr -> Meteo -> wind_speed /= pAbr -> Meteo -> counter_speed;
		pAbr -> pLeft = averageAbr(pAbr -> pLeft);
		pAbr -> pRight = averageAbr(pAbr -> pRight);
		return pAbr;
	}
}

void recreateAbr(Abr** pAbr, Abr* pAbr_tmp){
	if(pAbr_tmp != NULL){
		pAbr_tmp -> Meteo -> value_sorted = 1;  //Change the value to recreate the Abr tree with the Height sort method
		*pAbr = insertAbr(*pAbr, pAbr_tmp -> Meteo -> moisture, pAbr_tmp -> Meteo);
		recreateAbr(pAbr, pAbr_tmp -> pLeft);
		recreateAbr(pAbr, pAbr_tmp -> pRight);
	}
}

