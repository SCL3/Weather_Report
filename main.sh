#!/bin/bash

make > /dev/null  #Use the Make file for the .c programs

help()
{
	#Display help
	echo "This script filter and sort a meteo data csv file (specialy the one we are using in this project) depending on the option we are selecting"
	echo
	echo "Syntax : (bash) main.sh [argument]<option>"
	echo "Argument :"
	echo
	echo "--help     Show this help text" 
	echo "Exemple : bash main.sh --help"
	echo
	echo "-f [file]     Select the meteo data file (THIS COMMAND IS ESSENTIAL)"
	echo "Exemple : bash main.sh -f meteo_data.csv"
	echo
	echo "-t<1|2|3>     Create a file containing the temperature depending of the option : 1) Average temperature, minimum et maximum temperature depending of the station)"
	echo "                                                                                 2) Average temperature depending of the time"
	echo "                                                                                 3) Average temperature depending of the time and the station"
	echo "Exemple : bash main.sh -f meteo_data.csv -t2"
	echo
	echo "-p<1|2|3>     Create a file containing the atmospheric pressure depending of the option : 1) Average atmospheric pressure depending of the station"
	echo "                                                                                          2) Average atmospheric pressure depending of the time"
	echo "                                                                                          3) Average atmospheric pressure depending of the time and the station"
	echo "Exemple : bash main.sh -f meteo_data_data.csv -p1"
	echo
	echo "-w      Create a file containing the wind with the average direction and average wind speed for each station"
	echo "Exemple : bash main.sh -f meteo_data.csv -w"
	echo
	echo "-h      Create a file containing the height for each station"
	echo "Exemple : bash main.sh -f meteo_data.csv -h"
	echo
	echo "-m      Create a file containing the maximum moisture for each station"
	echo "Exemple : bash main.sh -f meteo_data.csv -m"
	echo
	echo "-r      Ascending to descending mode or descending to ascending mode"
	echo "Exemple : bash main.sh -f meteo_data.csv -m -r"
	echo
	echo "--avl    Choose the avl sort mode, the fatest (default sort mode)"
	echo "Exemple : bash main.sh -f meteo_data.csv -m --avl"
	echo
	echo "--abr    Choose the abr sort mode, slower than the avl mode"
	echo "Exemple : bash main.sh -f meteo_data.csv -h --abr"
	echo
	echo "--tab    Choose the tab sort mode, the slowest (with the use of nodes)"
	echo "Exemple : bash main.sh -f meteo_data.csv -w --tab"
	echo
}


if [[ $1 == '--help' ]]; then
	help
	exit
fi

echo "Number of argument : "$#

verif=0  #value that will check if the -f command is used
verif2=0  #value that will check if the sort mode method command is used once only
ascending=1
sort_mode='avl'

########### Check every options ###############################################

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
		'--avl') sort_mode="avl" ; verif2=$(( $verif2 + 1 )) ; echo "Sort mode : avl" 
			;;
		'--abr') sort_mode="abr" ; verif2=$(( $verif2 + 1 )) ; echo "Sort mode : abr"
			;;
		'--tab') sort_mode="tab" ; verif2=$(( $verif2 + 1 )) ; echo "Sort mode : tab"
			;;
	esac	
done

###### Check the meteo file #####################################

if [[ $verif -eq 0 ]]; then  #If the argument "-f" is not used :
	echo "There is no meteo data file selected, please use -f [file_name.csv], use --help for more details"
	exit 2  #Exit the program
elif  [[ $verif -eq 2 ]]; then  #Else if the meteo data file does not exist :
	echo "The meteo data file '$file_name' does not exist, please use -f [file_name.csv], use --help for more details"
	exit 2
fi

###### Check the sort method ####################################

if [[ $verif2 -ge 2 ]] ; then  #If the sort mode method command is used more than once
	echo "Please choose between '--avl' '--abr' '--tab', use --help for more details"
	exit 2
elif [[ $verif2 -eq 0 ]] ; then  #If there is no sort mode chosed, then the default sort mode is used (Avl)
	echo "Default sort mode : avl" 
fi

########### Check the geographic limitation #####################

for i in $(seq 1 $#) ; do  
	ARG=${!i}
	case $ARG in 
		'-F')  echo "France + Corsica" ; awk 'FS=";" {if($1 >= 7005 && $1 <= 7790) print}' $file_name > meteo_sorted.csv ; stock=$file_name ; file_name=meteo_sorted.csv
			;;
		'-G')  echo "Guyana" ; awk 'FS=";" {if($1 >= 81401 && $1 <= 81415) print}' $file_name > meteo_sorted.csv ; stock=$file_name ; file_name=meteo_sorted.csv
			;;
		'-S')  echo "Saint-Pierre and Miquelon" ; awk 'FS=";" {if($1 == 71805) print}' $file_name > meteo_sorted.csv ; stock=$file_name ; file_name=meteo_sorted.csv
			;;
		'-A')  echo "West Indies" ; awk 'FS=";" {if($1 >= 78890 && $1 <= 78925) print}' $file_name > meteo_sorted.csv ; stock=$file_name ; file_name=meteo_sorted.csv
			;;
		'-O')  echo "Indian Ocean" ; awk 'FS=";" {if($1 >= 61968 && $1 <= 67005) print}' $file_name > meteo_sorted.csv ; stock=$file_name ; file_name=meteo_sorted.csv
			;;
		'-Q')  echo "Antarctic" ; awk 'FS=";" {if($1 == 89642) print}' $file_name > meteo_sorted.csv ; stock=$file_name ; file_name=meteo_sorted.csv
			;; 
	esac	
done

###### The main function ########################################

for i in $(seq 1 $#) ; do  #Do the option for each arguments
	ARG=${!i}  
	case $ARG in
		'-f' | $file_name | '--help' | '-r' | '--tab' | '--abr' | '--avl' | '-F' | '-G' | '-S' |  '-A' | '-O' | '-Q' | $stock)  #Do nothing to avoid displaying the unknown argument statement.
			;;

		'-t'*) case $ARG in  #Create a csv file depending of the mode chosen
				'-t1') cut -d ';' -f 1,10,11 $file_name > temperature1.csv ; ./exec temperature1.csv temperature1_sorted.txt $ascending $sort_mode ; gnuplot gnu_temperature1.gnu #Average temperature, minimum et maximum temperature depending of the station
					;;
				'-t2') cut -d ';' -f 2,11 $file_name > temperature2.csv ; ./exec temperature2.csv temperature2_sorted.txt $ascending $sort_mode ; gnuplot gnu_temperature2.gnu #Average temperature depending of the time
					;;
				'-t3') cut -d ';' -f 1,2,11 $file_name > temperature3.csv ; ./exec temperature3.csv temperature3_sorted.txt $ascending $sort_mode #Average temperature depending of the time and the station
					;;
				*) echo "Unknown option '$ARG', please choose between '-t1' '-t2' '-t3', use --help for more details"	
				esac
			;;
		'-p'*) case $ARG in   #Create a csv file depending of the mode chosen
				'-p1') cut -d ';' -f 1,7,10 $file_name > pressure1.csv ; ./exec pressure1.csv pressure1_sorted.txt $ascending $sort_mode ; gnuplot gnu_pressure1.gnu  #Average atmospheric pressure depending of the station
					;;
				'-p2') cut -d ';' -f 2,7 $file_name > pressure2.csv ; ./exec pressure2.csv pressure2_sorted.txt $ascending $sort_mode ; gnuplot gnu_pressure2.gnu  #Average atmospheric pressure depending of the time
					;;
				'-p3') cut -d ';' -f 1,2,7 $file_name > pressure3.csv  #Average atmospheric pressure depending of the time and the station
					;;
				*) echo "Unknown option '$ARG', please choose between '-p1' '-p2' '-p3', use --help for more details"	
				esac
			;;
		'-w') cut -d ';' -f 1,4,5,10 $file_name > wind.csv ; ./exec wind.csv wind_sorted.txt $ascending $sort_mode #Create a csv file containing the average orientation and the average speed for each station.
			;;
		'-h') cut -d ';' -f 1,10,14 $file_name > height.csv ; ./exec height.csv height_sorted.txt $ascending $sort_mode ; gnuplot gnu_height.gnu  #Create a csv file containing the height of each station.
			;;
		'-m') cut -d ';' -f 1,6,10 $file_name > moisture.csv ; ./exec moisture.csv moisture_sorted.txt $ascending $sort_mode ; gnuplot gnu_moisture.gnu #create a csv file containing the maximum humidity for each station.
			;;
		*) echo "Unknown argument '$ARG', use --help for more details"  #The argument given is not treated.
	esac
done
