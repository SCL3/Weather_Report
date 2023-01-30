#!bin/bash

make > /dev/null

help()
{
	#Display help
	echo "This script filter and sort a meteo data csv file (specialy the one we are using in this project) depending on the option we are selecting"
	echo
	echo "Syntax : main.sh [argument]<option>"
	echo "Options :"
	echo "--help     Show this help text" 
	echo "-f [file]     Select the meteo data file"
	echo "-r Ascending to descending mode"
	echo "-t<1|2|3>     Create a file containing the temperature depending of the option : 1) Average temperature, minimum et maximum temperature depending of the station)"
	echo "                                                                                 2) Average temperature depending of the time"
	echo "                                                                                 3) Average temperature depending of the time and the station"
	echo "-p<1|2|3>     Create a file containing the atmospheric pressure depending of the option : 1) Average atmospheric pressure depending of the station"
	echo "                                                                                          2) Average atmospheric pressure depending of the time"
	echo "                                                                                          3) Average atmospheric pressure depending of the time and the station"
	echo "-w     Create a file containing the wind with the average direction and average wind speed for each station"
	echo "-h     Create a file containing the height for each station"
	echo "-m     Create a file containing the maximum moisture for each station"
	echo
}


echo "Number of argument : "$#
if [[ $1 == '--help' ]]; then
	help
fi


verif=0  #value that will check if the -f command is used
verif2=0  #value that will check if the sort mode method command is used once only
ascending=1
sort_mode='avl'
for i in $(seq 1 $#) ; do  #Check if the "-f" argument is used
	ARG=${!i}
	case $ARG in 
		'-f') 
			(( file_value=$i+1 ))  #The next argument is the file name of the meteo data
			file_name=${!file_value}
			if [ -f "$file_name" ]; then  #Check if the meteo data file does exist
				verif=1
			else
				verif=2
			fi
			;;
		'-r') ascending=0 ; echo "reversed order mode"
			;;
		'-avl') sort_mode="avl" ; verif2=$(( $verif2 + 1 )) ; echo "sort mode : avl" 
			;;
		'-abr') sort_mode="abr" ; verif2=$(( $verif2 + 1 )) ; echo "sort mode : abr"
			;;
		'-tab') sort_mode="tab" ; verif2=$(( $verif2 + 1 )) ; echo "sort mode : tab"
			;; 
	esac	
done

###### Check the meteo file #####################################

if [[ $verif -eq 0 ]]; then  #If the argument "-f" is not used :
	echo "There is no meteo data file selected, please use -f [file_name.csv]"
	exit 2  #Exit the program
elif  [[ $verif -eq 2 ]]; then  #Else if the meteo data file does not exist :
	echo "The meteo data file '$file_name' does not exist"
	exit 2
fi

###### Check the sort method ####################################

if [[ $verif2 -ge 2 ]] ; then  #If the sort mode method command is used more than once
	echo "Please use choose between '-avl' '-abr' '-tab'"
	exit 2
fi

###### The main function ########################################

for i in $(seq 1 $#) ; do  #Do the option for each arguments
	ARG=${!i}  
	case $ARG in
		'-f' | $file_name | '--help' | '-r' | '-tab' | '-abr' | '-avl')  #Do nothing to avoid displaying the unknown argument statement.
			;;

		'-t'*) echo "Temperature" ; case $ARG in  #Create a csv file depending of the mode chosen
				'-t1') cut -d ';' -f 1,11,12,13 $file_name > temperature.csv  #Average temperature, minimum et maximum temperature depending of the station
					;;
				'-t2') cut -d ';' -f 2,11 $file_name > temperature.csv  #Average temperature depending of the time
					;;
				'-t3') cut -d ';' -f 1,2,11 $file_name > temperature.csv  #Average temperature depending of the time and the station
					;;
				*) echo "Unknown option, use --help for more details"	
				esac
			;;
		'-p'*) echo "Atmospheric pressure" ; case $ARG in   #Create a csv file depending of the mode chosen
				'-p1') cut -d ';' -f 1,7 $file_name > atmo_pressure.csv  #Average atmospheric pressure depending of the station
					;;
				'-p2') cut -d ';' -f 2,7 $file_name > atmo_pressure.csv  #Average atmospheric pressure depending of the time
					;;
				'-p3') cut -d ';' -f 1,2,7 $file_name > atmo_pressure.csv  #Average atmospheric pressure depending of the time and the station
					;;
				*) echo "Unknown option, use --help for more details"	
				esac
			;;
		'-w') echo "Wind" ; cut -d ';' -f 1,4,5 $file_name > wind.csv #Create a csv file containing the average orientation and the average speed for each station.
			;;
		'-h') echo "Height" ; cut -d ';' -f 1,10,14 $file_name > height.csv ; ./exec height.csv height_sorted.txt $ascending $sort_mode #Create a csv file containing the height of each station.
			;;
		'-m') echo "Moisture" ; cut -d ';' -f 1,6 $file_name > moisture.csv ; ./exec moisture.csv moisture_sorted.txt $ascending $sort_mode #create a csv file containing the maximum humidity for each station.
			;;
		*) echo "Unknown argument '$ARG', use --help for more details"  #The argument given is not treated.
	esac
done
