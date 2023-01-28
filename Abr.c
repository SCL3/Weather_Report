
#include "head.h"

Mto* createMto(){
	Mto* pNew = malloc(sizeof(Mto));
	if(pNew == NULL){  // Check if the malloc worked
		exit(4);
	}
	return pNew;
}

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

int search(Abr* pTree, int a) {
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

Abr* insertRec(Abr* pTree, int val, Mto* meteo){
    if(pTree == NULL){
        return create(val, meteo);
    }
    if(val < pTree -> value){
        pTree -> pLeft = insertRec(pTree -> pLeft, val, meteo);
    }
    if(val > pTree -> value){
        pTree -> pRight = insertRec(pTree -> pRight, val, meteo);
    }
    return pTree;
}


void recreateAbr(Abr** pAbr, Abr* pAbr_tmp){
	if(pAbr_tmp != NULL){
		pAbr_tmp -> Meteo -> value_sorted = 1;  //Change the value to recreate the Avl tree with the Height sort method
		*pAbr = insertAbr(*pAbr, pAbr_tmp -> Meteo -> moisture, pAbr_tmp -> Meteo);
		recreateAbr(pAbr, pAbr_tmp -> pLeft);
		recreateAbr(pAbr, pAbr_tmp -> pRight);
	}
}

int descending_csv_h(FILE* output ,Abr* pAbr){
	if(pAbr != NULL){
		descending_csv_h(output, pAbr -> pRight);
		fprintf(output, "%d;%d\n", pAbr -> Meteo -> station, pAbr -> value);
		descending_csv_h(output, pAbr -> pLeft);
	}
	return 0;
}

int ascending_csv_h(FILE* output ,Abr* pAbr){
	if(pAbr != NULL){
		ascending_csv_h(output, pAbr -> pLeft);
		fprintf(output, "%d;%d\n", pAbr -> Meteo -> station, pAbr -> value);
		ascending_csv_h(output, pAbr -> pRight);
	}
	return 0;
}


