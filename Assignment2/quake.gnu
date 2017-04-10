f(x)=5.3869+-0.799356*x
set title 'Gutenberg-Richter Law'
set xlabel 'Magnitude M'
set ylabel 'log_10(N) per bin'
set xrange [0:10]
plot f(x) title '5.3869 - 0.799356 M', 'histogram.dat' with points, 'histogram.dat' with impulses lw 2
