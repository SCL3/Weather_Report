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
#include "node_struct.h"

/////// mto Structure functions /////////////////////////////////

Mto* createMto();

/////// AVL Functions /////////////////////////////////////////

Avl* createAvl(int val, Mto* meteo);

void infixeAvl_h(Avl* pTree);  //Display function

void infixeDecAvl_h(Avl* pTree);  //Display function

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

/////// ABR Functions /////////////////////////////////////////

Abr* createAbr(int val, Mto* meteo);

void infixeAbr_h(Abr* pTree);  //Display function

void infixeDecAbr_h(Abr* pTree);  //Display function

int Abr_check(Abr* pTree);  //Display function

int search(Abr* pTree, int a);  //Display function

Abr* insertAbr(Abr* pAbr, int a, Mto* meteo);

void recreateAbr(Abr** pAbr, Abr* pAbr_tmp);

/////// Node Functions /////////////////////////////////////////

Node* createNode(int val, Mto* meteo);

Node* asc_insertNode(Node* pHead, int val, Mto* meteo);

Node* desc_insertNode(Node* pHead, int val, Mto* meteo);

void desc_recreateNode(Node** pHead, Node* pHead_tmp);

void asc_recreateNode(Node** pHead, Node* pHead_tmp);

void displayList(Node* pHead);

//////// CSV File creator functions //////////////////////////////////////////////

int descending_csv_Avl(FILE* output ,Avl* height_avl);

int ascending_csv_Avl(FILE* output ,Avl* height_avl);

int descending_csv_Abr(FILE* output ,Abr* pAbr);

int ascending_csv_Abr(FILE* output ,Abr* pAbr);

int csv_Node(FILE* output ,Node* pHead);

////// Functions to sort a specific data /////////////////////////////////////////////////

int height(char* output_fname, int ascending, int sort_mode);

int moisture(char* output_fname, int ascending, int sort_mode);
