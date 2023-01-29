/////////////////////////////// ABR STRUCTURE ////////////////////////////////////

typedef struct _abr{  // Abr tree structure used to sort a specific value
	int value;
	Mto* Meteo;
	struct _abr* pLeft;
	struct _abr* pRight;
}Abr;
