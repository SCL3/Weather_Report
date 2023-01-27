//////////////////// AVL STRUCTUR/////////////////////////////////////////////////////////////

typedef struct _meteo{  // Meteo structure used to stock every value of a station
	int station;
	int height;
	int moisture;
	int value_sorted;  //The value represents the data to sort (1 : Height; 2 : Moisture; 
}Mto;

typedef struct _avl{  // Avl tree structure used to sort a specific value
	int value;
	Mto* Meteo;
	struct _avl* pLeft;
	struct _avl* pRight;
	int balance;
}Avl;
