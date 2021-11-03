gcc silly.c -fopenmp -lm 
for i in 1 2 3 4 5 6 7 8; do
  perf stat ./a.out
done
