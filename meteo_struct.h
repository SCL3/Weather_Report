//////////////////// METEO STRUCTURE ////////////////////////////////////////////////////////

typedef struct{  // Meteo structure used to stock every value of a station
	int station;
	double y;  // North if positive, South otherwise
	double x;  // East if positive, West otherwise
	double wind_direction; 
	double wind_speed;
	int height;
	int moisture;
	int counter_direction;
	int counter_speed;
	int temperature;
	int atmopressure;
	int value_sorted;  //The value represents the data to sort (1 : Height; 2 : Moisture; 3 : Wind ;
}Mto;
