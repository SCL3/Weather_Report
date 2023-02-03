//////////////////// METEO STRUCTURE ////////////////////////////////////////////////////////

typedef struct{  // Meteo structure used to stock every value of a station
	int station;  //Station
	double y;  // North if positive, South otherwise
	double x;  // East if positive, West otherwise
	
	double wind_direction;  //Wind 
	double wind_speed;
	int counter_direction;
	int counter_speed;
	
	int height;  //Height
	
	int moisture;  //Moisture
	
	double temp_or_pres;  //Temperature or atmospheric pressure
	double min_value;
	double max_value;
	int counter;
	
	Time* Time;  //Time structure
	
	int value_sorted;  //The value represents the data to sort (1 : Height (Moisture); 2 : Moisture; 3 : Wind ; 4 : Temperature and Atmospheric Pressure
}Mto;
