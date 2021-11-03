gcc sieve.c -fopenmp -lm 
for i in 1 2 3 4 5 6 7 8; do
  time ./a.out
done