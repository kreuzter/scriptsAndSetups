set terminal png 
set output 'residua.png'

set logscale y
set ylabel 'residua'
set xlabel 'Iteration'
set grid

set format y "10^{%T}"

plot "< cat log | grep 'GMRES iteration: 0   Residual: '        | sed 's/GMRES iteration: 0   Residual: //g' | sed 's/\s\(.*\)//g' " using 0:1 lc 1 lw 1 title 'GMRES' with lines,\
     "< cat log | grep 'smoothSolver:  Solving for omega, I'    | sed 's/smoothSolver:  Solving for omega, Initial residual = //g' | sed 's/,.*//g' " lc 3 lw 1 title 'omega'  with lines,\
     "< cat log | grep 'smoothSolver:  Solving for k, I'        | sed 's/smoothSolver:  Solving for k, Initial residual = //g' | sed 's/,.*//g' " lc 4 lw 1 title 'k'      with lines, \
     "< cat log | grep 'smoothSolver:  Solving for ReThetat, I' | sed 's/smoothSolver:  Solving for ReThetat, Initial residual = //g' | sed 's/,.*//g' " lc 5 lw 1 title 'ReThetat'  with lines,\
     "< cat log | grep 'smoothSolver:  Solving for gammaInt, I' | sed 's/smoothSolver:  Solving for gammaInt, Initial residual = //g' | sed 's/,.*//g' " lc 6 lw 1 title 'gammaInt'  with lines
