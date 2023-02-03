////////////// Time structure /////////////////////////////////////////////////

typedef struct{  //Time structure, used to store the time format
	int year;
	int month;
	int day;
	int hour;  //There's no minute and seconde
	int jet_lag;  //It means "decalage horaire" in France
	int value;  //A sort of total calculated with the time
}Time;
