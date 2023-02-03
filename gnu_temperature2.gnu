#!/bin/gnuplot


# Specify date and time format
set xdata time
set timefmt "%Y-%m-%dT%H:%M:%S%z"

# Specify labels for the x and y axes
set xlabel "Date and hour "
set ylabel "temperature"
set xrange ['2009-08-1T00:00:00:00:00' : '2023-1-1T00:00:00:00:00']
set yrange [-80:80]

set datafile separator ";"
set terminal png
set output 'graph_temperature2_sorted.png'

# Load data from a CSV file with the first column representing measurement dates and times and the second column representing atmospheric pressure measurements
plot "temperature2_sorted.txt" using 1:($2) title "Average temperature" with lines linetype rgb "red"
