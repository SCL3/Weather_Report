////// Mto Structure functions /////////////////////////////////////////////

#include "head.h"

Mto* createMto(){
	Mto* pNew = malloc(sizeof(Mto));
	if(pNew == NULL){  // Check if the malloc worked
		exit(4);
	}
	return pNew;
}
