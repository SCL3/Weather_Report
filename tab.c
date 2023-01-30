
#include "head.h"

void Fusion(Node *tab, int SIZE, int beginning, int middle, int end){
	int indexa = beginning;
	int indexb = end;
	Node *tab2[SIZE];	
	for(int i = beginning; i < middle+1; i++){
		tab2[i] = tab[i];
	}
	for(int k = middle+1; k <end+1; k++){
		tab2[k] = tab[end-k+middle+1]; 
	}
	for(int l = beginning; l < end-k+1; l++){
		if (tab2[indexa].value <= tab2[indexb].value){
			tab[l] = tab2[indexa];
			indexa++;
		}
		else{
			tab[l] = tab2[indexb];
			indexb--;
		}
	}
}


void triFusion1(Node *tab, int SIZE, int beginning, int end){
	int middle = (beginning + end)/2;
	if(beginning < end){
		triFusion1(tab, SIZE, beginning, middle);
		triFusion1(tab, SIZE, middle+1, end);
		Fusion(tab, beginning, SIZE, middle, end);
	}
}

void triFusion(Node *tab, int SIZE){
	triFusion1(tab, SIZE, 0, SIZE-1);
}
