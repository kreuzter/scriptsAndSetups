set terminal png 
set output 'avdr.png'

set ylabel 'AVDR'
set xlabel 'Iteration'
set grid

plot "< cat log | grep 'AVDR = '        | sed 's/AVDR = //g' | sed 's/\s\(.*\)//g' " using 0:1 lc 1 lw 1 title 'AVDR' with lines,