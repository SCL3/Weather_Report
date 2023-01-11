#include <stdlib.h>
#include <stdio.h>

typedef struct _abr{
    int value;
    struct _abr* pLeft;
    struct _abr* pRight;
}Abr;

// tri abr

Abr* create(int a){
    Abr* pNew = malloc(sizeof(Abr));
    if(pNew == NULL){
        exit(1);
    }
    pNew -> value = a;
    pNew -> pLeft = NULL;
    pNew -> pRight = NULL;
    return pNew;

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


Abr* insertRec(Abr* pTree, int a){
    if(pTree == NULL){
        return create(a);
    }
    if(a < pTree -> value){
        pTree -> pLeft = insertRec(pTree -> pLeft, a);
    }
    if(a > pTree -> value){
        pTree -> pRight = insertRec(pTree -> pRight, a);
    }
    return pTree;
}

void prefixe(Abr* pTree){
    if(pTree != NULL){
        printf("%d|", pTree -> value);
        prefixe(pTree -> pLeft);
        prefixe(pTree ->pRight);
    }
}



// tri insertion
void tri_insertion(int tab[], int nb)
{
     int x,j;
     for(int i = 0 ; i <= n - 1 ; i++)
     {
             x = tab[i];
             j = i;
             while( j > 0 & tab[j-1] > x )
             {
                    tab[j] = tab[j-1];
                    j = j - 1;
             }
             tab[j] = x;
     }
}

      

int main(){



	/*int nb;
	tri_insertion(T,nb);
	for (int i=0 ; i< nb ; i++) {
		printf("%d ",tab[i]);
	}*/
	
	
	
	return 0;
}








