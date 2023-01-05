#include <stdio.h>
#include <stdlib.h>

typedef struct _avl{
	int value;
	int value2;
	struct _avl* pLeft;
	struct _avl* pRight;
	int balance;
}Avl;

Avl* createAvl(int val, int val2){
	Avl* pNew = malloc(sizeof(Avl));
	if(pNew == NULL){
		exit(4);
	}
	pNew -> value = val;
	pNew -> value2 = val2;
	pNew -> pLeft = NULL;
	pNew -> pRight = NULL;
	pNew -> balance = 0;
	return pNew;
}

void infixeAvl(Avl* pTree){
    if(pTree != NULL){
        infixeAvl(pTree -> pLeft);
        printf("val : %d et eq : %d \n", pTree -> value, pTree -> balance);
        infixeAvl(pTree -> pRight);
    }
}

void infixeDecAvl(Avl* pTree){
    if(pTree != NULL){
        infixeDecAvl(pTree -> pRight);
        printf("station : %d et altitude : %d \n", pTree -> value, pTree -> value2);
        infixeDecAvl(pTree -> pLeft);
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

Avl* insertAvl_bis(Avl* pAvl, int a, int b, int* h){
	if(pAvl == NULL){  //Create a new tree for the avl
		*h = 1;
		return createAvl(a, b);
	}
	else if(a < pAvl -> value){
		pAvl -> pLeft = insertAvl_bis(pAvl -> pLeft, a, b, h);
		*h = -*h;
	}
	else if(a > pAvl -> value){
		pAvl -> pRight = insertAvl_bis(pAvl -> pRight, a, b, h);
	}
	else{  //If the value already exist
		*h = 0;
		return pAvl;
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

Avl* insertAvl(Avl* pAvl, int a, int b){
 	int h;
	return insertAvl_bis(pAvl, a, b, &h);
}
