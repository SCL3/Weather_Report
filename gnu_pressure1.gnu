#!/bin/gnuplot

set datafile separator ";"
set terminal png
set output 'graph_pressure_sorted.png'
set xlabel "stations"
set ylabel "pressure" 
set title "p1 pressure depending on stations "
set xtics rotate by 90 right
set yrange [11000:130000]
plot "pressure_sorted.txt" using 0:2:3:xticlabels(1) with filledcurves fc rgb "#7f7f7f" title "pressure max/min", \
"" using 0:4:xticlabels(1) smooth mcspline lc rgb "#0000000" lw 2 title "average pressure"
