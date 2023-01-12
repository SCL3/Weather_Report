#include <stdio.h>
#include <stdlib.h>

Avl* createAvl(int val, int val2);

void infixeAvl_h(Avl* pTree);

void infixeDecAvl_h(Avl* pTree);

int max(int val1, int val2, int val3);

int min(int val1, int val2, int val3);

Avl* leftRotation(Avl* pAvl);

Avl* rightRotation(Avl* pAvl);

Avl* doubleLeftRotation(Avl* pAvl);

Avl* doubleRightRotation(Avl* pAvl);

Avl* balanceAvl(Avl* pAvl);

Avl* insertAvl_bis(Avl* pAvl, int a, int b, int* h);

Avl* insertAvl(Avl* pAvl, int a, int b);

int descending_csv_h(FILE* output ,Avl* height_avl);