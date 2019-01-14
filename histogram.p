#
set title "Prognoza ocen z PWI po liście 10"
set yrange [0:18]
set style data histogram
set style histogram cluster gap 1
set style fill solid border-1
set boxwidth 0.9
set xtic rotate by -270
set datafile separator ';'
plot for [COL=2:7] 'oceny.csv' using COL:xticlabels(1) title columnheader
#
