//////////////////// METEO STRUCTURE ////////////////////////////////////////////////////////

typedef struct{  // Meteo structure used to stock every value of a station
	int station;
	int height;
	int moisture;
	int value_sorted;  //The value represents the data to sort (1 : Height; 2 : Moisture; 
}Mto;
