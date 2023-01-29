/*
	Code created by Mohamed and SIIMOON the ../../2022
	Last update : ../../2023
	A shell code used to read a csv file, select the data, 
	send it to a 'c' code to sort it depending of the value selected (code 'c' created by us),
	the c code will create a new file and a gnu code will read it (code 'gnu' created by us).
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "meteo_struct.h"
#include "avl_struct.h"
#include "abr_struct.h"

Mto* createMto();

Avl* createAvl(int val, Mto* meteo);

void infixeAvl_h(Avl* pTree);

void infixeDecAvl_h(Avl* pTree);

int max(int val1, int val2, int val3);

int min(int val1, int val2, int val3);

Avl* leftRotation(Avl* pAvl);

Avl* rightRotation(Avl* pAvl);

Avl* doubleLeftRotation(Avl* pAvl);

Avl* doubleRightRotation(Avl* pAvl);

Avl* balanceAvl(Avl* pAvl);

Avl* insertAvl_bis(Avl* pAvl, int val, Mto* meteo, int* h);

Avl* insertAvl(Avl* pAvl, int a, Mto* meteo);

void recreateAvl(Avl** pAvl, Avl* pAvl_tmp);

int descending_csv_h(FILE* output ,Avl* height_avl);

int ascending_csv_h(FILE* output ,Avl* height_avl);
