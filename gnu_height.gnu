#!/bin/gnuplot


set datafile separator ";"
set title "interpolated station's height map"
set xlabel "Longitude"
set ylabel "Latitude"
set cblabel "height"
set yrange [-69:57]
set xrange [-67:146]
set pm3d map
set dgrid3d 140,140,4
set view map
set terminal png
set output 'graph_height.png'
unset key
splot "height_sorted.txt" using 4:3:2 with pm3d







