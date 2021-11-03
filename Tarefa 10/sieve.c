/*

Henrique, não consegui pegar os dados usando o servidor Parcode porque lá a ferramenta não funciona, então decidi
medir os dados usando o meu PC mesmo. Ainda assim ficou faltando 1 dado: o LL cache hits.
No meu PC aparece a flag <not supported> no lugar de LL-cache hits.

Meu PC: 
Ryzen 5 5600X - 6 Cores 12 Threads
Arch Linux 5.13.13-arch1-1
GCC 11.1.0

=======================
Tempo - Sequencial
=======================


=======================
Tempo - Paralelo(static)
=======================


=======================
Tempo - Paralelo(dynamic)
=======================


=======================
Tempo - Paralelo(guided)
=======================


=======================
Tempo - Paralelo(auto)
=======================

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
   //omp_set_num_threads(2);
   
   // Create a boolean array "prime[0..n]" and initialize
   // all entries it as true. A value in prime[i] will
   // finally be false if i is Not a prime, else true.
   int primes = 0; 
   bool *prime = (bool*) malloc((n+1)*sizeof(bool));
   int sqrt_n = sqrt(n);
     
   memset(prime, true,(n+1)*sizeof(bool));

   int i, p;
   
   //#pragma omp parallel for schedule(auto)
   for (p=2; p <= sqrt_n; p++)
   {
       // If prime[p] is not changed, then it is a prime
       if (prime[p] == true)
       {
         // Update all multiples of p
         //#pragma omp parallel for schedule(auto)
		   for(i=p*2; i<=n; i += p)
	           prime[i] = false;
       }
   }
   
   // count prime numbers
	//#pragma omp parallel for reduction(+:primes) schedule(auto)
	for (int p=2; p<=n; p++)
       if (prime[p])
         primes++;
 
      return(primes);
   }
     
int main()
{
   int n = 100000000;
   //printf("%d\n",sieveOfEratosthenes(n));
   sieveOfEratosthenes(n);
   return 0;
} 
