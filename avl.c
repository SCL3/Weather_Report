/////// AVL Functions ///////////////////////////////////////////

#include "head.h"

Avl* createAvl(int val, Mto* meteo){
	Avl* pNew = malloc(sizeof(Avl));
	if(pNew == NULL){  // Check if the malloc worked
		exit(4);
	}
	pNew -> value = val;
	pNew -> Meteo = meteo;
	pNew -> pLeft = NULL;
	pNew -> pRight = NULL;
	pNew -> balance = 0;
	return pNew;
}

void infixeAvl_h(Avl* pTree){  //ascending order
    if(pTree != NULL){
        infixeAvl_h(pTree -> pLeft);
        printf("val : %d et eq : %d \n", pTree -> value, pTree -> balance);
        infixeAvl_h(pTree -> pRight);
    }
}

void infixeDecAvl_h(Avl* pTree){  //descending order
    if(pTree != NULL){
        infixeDecAvl_h(pTree -> pRight);
        printf("altitude : %d et station : %d\n", pTree -> value, pTree -> Meteo -> height);
        infixeDecAvl_h(pTree -> pLeft);
    }
}


int max(int val1, int val2, int val3){
	int max;
	if(val1 > val2){
		max = val1;
	}
	else{
		max = val2;
	}
	if(max > val3){
		return max;
	}
	return val3;
}

int min(int val1, int val2, int val3){
	int min;
	if(val1 < val2){
		min = val1;
	}
	else{
		min = val2;
	}
	if(min < val3){
		return min;
	}
	return val3;
}

Avl* leftRotation(Avl* pAvl){
	Avl* pivot = NULL;
	int bal_a, bal_p;
	pivot = pAvl -> pRight;
	pAvl -> pRight = pivot -> pLeft;
	pivot -> pLeft = pAvl;
	bal_a = pAvl -> balance;
	bal_p = pivot -> balance;
	pAvl -> balance = bal_a - max(bal_p, bal_p, 0) - 1;
	pivot -> balance = min(bal_a-2, bal_a+bal_p-2, bal_p-1);
	pAvl = pivot;
	return pAvl;
}

Avl* rightRotation(Avl* pAvl){
	Avl* pivot = NULL;
	int bal_a, bal_p;
	pivot = pAvl -> pLeft;
	pAvl -> pLeft = pivot -> pRight;
	pivot -> pRight = pAvl;
	bal_a = pAvl -> balance;
	bal_p = pivot -> balance;
	pAvl -> balance = bal_a - min(bal_p, bal_p, 0) + 1;
	pivot -> balance = max(bal_a+2, bal_a+bal_p+2, bal_p+1);
	pAvl = pivot;
	return pAvl;
}

Avl* doubleLeftRotation(Avl* pAvl){
	pAvl -> pRight = rightRotation((pAvl -> pRight));
	return leftRotation(pAvl);
}

Avl* doubleRightRotation(Avl* pAvl){
	pAvl -> pLeft = leftRotation((pAvl -> pLeft));
	return rightRotation(pAvl);
}

Avl* balanceAvl(Avl* pAvl){
	if(pAvl -> balance >= 2){
		if(pAvl -> pRight -> balance >= 0){
			return leftRotation(pAvl);
		}
		else{
			return doubleLeftRotation(pAvl);
		}
	}
	else if(pAvl -> balance <= -2){
		if(pAvl -> pLeft -> balance <= 0){
			return rightRotation(pAvl);
		}
		else{
			return doubleRightRotation(pAvl);
		}
	}
	return pAvl;
}

Avl* insertAvl_bis(Avl* pAvl, int val, Mto* meteo, int* h){
	if(pAvl == NULL){  //Create a new tree for the avl
		*h = 1;
		return createAvl(val, meteo);
	}
	else if(val < pAvl -> value){
		pAvl -> pLeft = insertAvl_bis(pAvl -> pLeft, val, meteo, h);
		*h = -*h;
	}
	else if(val > pAvl -> value){
		pAvl -> pRight = insertAvl_bis(pAvl -> pRight, val, meteo, h);
	}
	else{  //If the value already exist
		if(meteo -> value_sorted == 1){  //Sort mode for the Height
			if (meteo -> station < pAvl -> Meteo -> station){
				pAvl->pLeft= insertAvl_bis(pAvl -> pLeft, val, meteo, h);
				*h= -*h;
			}
			else if(meteo -> station > pAvl -> Meteo -> station){
				pAvl -> pRight = insertAvl_bis(pAvl -> pRight, val, meteo, h);
			}
			else {  //if the value and the station is the same
				*h=0;
				return pAvl;
			}
		}
		if(meteo -> value_sorted == 2){  //Sort mode for the Moisture
			if(meteo -> moisture > pAvl -> Meteo -> moisture){  //Replace the lowest moisture value with the highest 
				pAvl -> Meteo -> moisture = meteo -> moisture;
			}
			*h=0;
			return pAvl;
		}
	}
	if(*h != 0){  //If there is a change in the avl
		pAvl -> balance = pAvl -> balance + *h;
		pAvl = balanceAvl(pAvl);
		if(pAvl -> balance == 0){
			*h = 0;
		}
		else{
			*h = 1;
		}
	}
	return pAvl;
}

Avl* insertAvl(Avl* pAvl, int a, Mto* meteo){
 	int h;
	return insertAvl_bis(pAvl, a, meteo, &h);
}

void recreateAvl(Avl** pAvl, Avl* pAvl_tmp){
	if(pAvl_tmp != NULL){
		pAvl_tmp -> Meteo -> value_sorted = 1;  //Change the value to recreate the Avl tree with the Height sort method
		*pAvl = insertAvl(*pAvl, pAvl_tmp -> Meteo -> moisture, pAvl_tmp -> Meteo);
		recreateAvl(pAvl, pAvl_tmp -> pLeft);
		recreateAvl(pAvl, pAvl_tmp -> pRight);
	}
}
