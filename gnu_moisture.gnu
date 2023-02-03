#!/bin/gnuplot


set datafile separator ";"
set title "interpolated station's moisture map"
set xlabel "Longitude"
set ylabel "Latitude"
set cblabel "moisture"
set yrange [-69:57]
set xrange [-67:146]
set pm3d map
set dgrid3d 140,140,4
set view map
set terminal png
set output 'graph_moisture.png'
unset key
splot "moisture_sorted.txt" using 4:3:2 with pm3d





