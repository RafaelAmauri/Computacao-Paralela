/*
Tempo - Sequencial
5761455

real	0m3.999s
user	0m3.918s
sys	0m0.068s
5761455

real	0m4.013s
user	0m3.918s
sys	0m0.076s
5761455

real	0m4.179s
user	0m4.061s
sys	0m0.091s
5761455

real	0m3.981s
user	0m3.891s
sys	0m0.076s
5761455

real	0m4.311s
user	0m4.212s
sys	0m0.088s
5761455

real	0m4.318s
user	0m4.114s
sys	0m0.179s
5761455

real	0m4.049s
user	0m3.904s
sys	0m0.120s
5761455

real	0m4.454s
user	0m4.004s
sys	0m0.440s

Tempo - Paralelo
5761455

real	0m2.281s
user	0m8.659s
sys	0m0.089s
5761455

real	0m2.563s
user	0m9.498s
sys	0m0.295s
5761455

real	0m2.504s
user	0m9.418s
sys	0m0.231s
5761455

real	0m2.460s
user	0m9.175s
sys	0m0.275s
5761455

real	0m2.540s
user	0m9.627s
sys	0m0.184s
5761455

real	0m2.528s
user	0m9.669s
sys	0m0.102s
5761455

real	0m2.341s
user	0m8.716s
sys	0m0.227s
5761455

real	0m2.278s
user	0m8.696s
sys	0m0.072s
*/

/*
* Adapted from: http://w...content-available-to-author-only...s.org/sieve-of-eratosthenes
*/
     
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
     
int sieveOfEratosthenes(int n)
{
   // Create a boolean array "prime[0..n]" and initialize
   // all entries it as true. A value in prime[i] will
   // finally be false if i is Not a prime, else true.
   int primes = 0; 
   bool *prime = (bool*) malloc((n+1)*sizeof(bool));
   int sqrt_n = sqrt(n);
   
   omp_set_num_threads(2);  
   
   memset(prime, true,(n+1)*sizeof(bool));
   
   int i, p;
   
   #pragma omp parallel for
   for (p=2; p <= sqrt_n; p++)
   {
       // If prime[p] is not changed, then it is a prime
       if (prime[p] == true)
       {
         // Update all multiples of p
         #pragma omp parallel for schedule(dynamic)
		   for(i=p*2; i<=n; i += p)
	           prime[i] = false;
       }
   }
   
   // count prime numbers
	#pragma omp parallel for reduction(+:primes)
	for (int p=2; p<=n; p++)
       if (prime[p])
         primes++;
 
      return(primes);
   }
     
int main()
{
   int n = 100000000;
   printf("%d\n",sieveOfEratosthenes(n));
   return 0;
} 
