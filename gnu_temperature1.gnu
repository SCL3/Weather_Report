#!/bin/gnuplot

set datafile separator ";"
set terminal png
set output 'graph_temperature_sorted.png'
set xlabel "stations"
set ylabel "temperature" 
set title "t1 temperature depending on stations "
set xtics rotate by 90 right
set yrange [-80:90]
plot "temperature_sorted.txt" using 0:2:3:xticlabels(1) with filledcurves fc rgb "#888FF" title "temperature max/min", \
"" using 0:4:xticlabels(1) smooth mcspline lc rgb "#0000000" lw 2 title "average temperature"

