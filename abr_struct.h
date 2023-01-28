/////////////////////////////// ABR STRUCTUR ////////////////////////////////////



typedef struct _meteo{  // Meteo structure used to stock every value of a station
	int station;
	int height;
	int moisture;
	int value_sorted;  //The value represents the data to sort (1 : Height; 2 : Moisture; 
}Mto;

typedef struct _abr{  // Abr tree structure used to sort a specific value
	int value;
	Mto* Meteo;
	struct _abr* pLeft;
	struct _abr* pRight;
}Abr;
