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
	else if(meteo -> value_sorted == 4){  //Sort mode for the Temperature (or Pression)
		if(meteo -> temp_or_pres == -9999){  //If there is no meteo data
			return pAbr;
		}  
		if(meteo -> min_value < pAbr -> Meteo -> min_value || pAbr -> Meteo -> min_value == -9999){  //Replace the highest value with the lowest, the value can be created with the value -9999 !
			pAbr -> Meteo -> min_value = meteo -> min_value;
		}
		if(meteo -> max_value > pAbr -> Meteo -> max_value || pAbr -> Meteo -> max_value == -9999){  //Replace the lowest value with the highest 
			pAbr -> Meteo -> max_value = meteo -> max_value;
		}
		pAbr -> Meteo -> temp_or_pres += meteo -> temp_or_pres;  //Add the temperature (or pressure), to make a total 
		pAbr -> Meteo -> counter += 1; 
		}
	else if(meteo -> value_sorted == 5){  //Sort mode for the Temperature (or Pression) about the time
			if(meteo -> temp_or_pres == -9999){  //If there is no meteo data
				return pAbr;
			}
			if(pAbr -> Meteo -> temp_or_pres == -9999){  //if the first occurrence had no data
				pAbr -> Meteo -> temp_or_pres = meteo -> temp_or_pres;
				return pAbr;
			}
			pAbr -> Meteo -> temp_or_pres += meteo -> temp_or_pres;  //Add the temperature (or pressure), to make a total 
			pAbr -> Meteo -> counter += 1; 
		}
	}
    return pAbr;
}

Abr* averageAbr(Abr* pAbr){
	if(pAbr != NULL){
		if(pAbr -> Meteo -> value_sorted == 3){
			pAbr -> Meteo -> wind_direction /= pAbr -> Meteo -> counter_direction;
			pAbr -> Meteo -> wind_speed /= pAbr -> Meteo -> counter_speed;
			pAbr -> pLeft = averageAbr(pAbr -> pLeft);
			pAbr -> pRight = averageAbr(pAbr -> pRight);
		}
		else if(pAbr -> Meteo -> value_sorted == 4 || pAbr -> Meteo -> value_sorted == 5){
			pAbr -> Meteo -> temp_or_pres /= pAbr -> Meteo -> counter;
			pAbr -> pLeft = averageAbr(pAbr -> pLeft);
			pAbr -> pRight = averageAbr(pAbr -> pRight);
		}
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

