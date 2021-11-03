gcc sieve.c -o sieve -fopenmp -lm 
for i in 1 2 3 4 5 6 7 8; do
  time ./sieve 
done
