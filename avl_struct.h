//////////////////// AVL STRUCTURE/////////////////////////////////////////////////////////////

typedef struct _avl{  // Avl tree structure used to sort a specific value
	int value;
	Mto* Meteo;
	struct _avl* pLeft;
	struct _avl* pRight;
	int balance;
}Avl;
