set terminal pngcairo size 1400,900
set output 'residua.png'

set logscale y
set ylabel 'Initial residual'
set xlabel 'Iteration'
set grid
set key outside right top
set format y "10^{%T}"

# Robust extractor for both LUSGS and smoothSolver lines:
#   ... Solving for <var>, Initial residual = <value>, ...
res(var) = sprintf("< awk '/Solving for %s,/{ s=$0; sub(/^.*Initial residual = /, \"\", s); sub(/,.*/, \"\", s); print s }' log", var)

plot \
     "< awk '/GMRES iteration: 0   Residual:/{print $NF}' log" using 0:1 lc 1 lw 1 title 'GMRES' with lines, \
     res('rho')      using 0:1 lc 2 lw 1 title 'rho'      with lines, \
     res('rhoU')     using 0:1 lc 7 lw 1 title 'rhoU'     with lines, \
     res('rhoE')     using 0:1 lc 8 lw 1 title 'rhoE'     with lines, \
     res('omega')    using 0:1 lc 3 lw 1 title 'omega'    with lines, \
     res('k')        using 0:1 lc 4 lw 1 title 'k'        with lines, \
     res('ReThetat') using 0:1 lc 5 lw 1 title 'ReThetat' with lines, \
     res('gammaInt') using 0:1 lc 6 lw 1 title 'gammaInt' with lines
