#!/bin/gnuplot


set datafile separator ";"
set title "Carte interpolée de l'altitude des stations"
set xlabel "Longitude"
set ylabel "Latitude"
set cblabel "Altitude"
set pm3d map
set dgrid3d 140,140,4
set view map
set terminal png
set output 'graph.png'
splot "height_sorted.txt" using 4:3:2 with pm3d





set datafile separator ";"
set title "Carte des courants de vent dans les villes"
set xlabel "Latitude"
set ylabel "Longitude"
set size square
set arrowsize 0.5
set vectors head filled lw 2
set terminal png
set output 'graphvent.png'
plot "height_sorted.txt" using 1:2:3:4 with vectors notitle

