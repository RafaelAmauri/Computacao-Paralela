/*
Henrique, eu resolvi testar no meu proprio PC ao inves do server da PUC, porque 
lá demora demais, e se um unico aluno alem de mim resolver testar, o programa dele
vai ocupar CPU time junto com o meu e os tempos vao ficar diferentes. Preferi testar no meu PC
tambem porque assim eu consigo ter controle de quais programas rodam em background e saber que eu fechei tudo,
pra minha CPU ficar exclusivamente pra rodar esse codigo.

Config do meu PC:
AMD Ryzen 5 5600X (6 cores 12 threads)
Arch Linux - 5.13.12-arch1-1
GCC 11.1.0

Tempo - Sequencial
real	0m24.447s
user	0m24.413s
sys	0m0.023s

real	0m24.433s
user	0m24.406s
sys	0m0.017s

real	0m24.379s
user	0m24.231s
sys	0m0.093s

real	0m24.330s
user	0m24.173s
sys	0m0.083s

real	0m24.346s
user	0m24.319s
sys	0m0.017s

real	0m24.370s
user	0m24.340s
sys	0m0.020s

real	0m24.416s
user	0m24.382s
sys	0m0.023s

real	0m24.415s
user	0m24.379s
sys	0m0.027s

==========================

Tempo - Paralelo

real	0m3.762s
user	0m43.229s
sys	0m1.277s

real	0m3.746s
user	0m43.324s
sys	0m1.323s

real	0m3.726s
user	0m42.869s
sys	0m1.232s

real	0m3.761s
user	0m43.387s
sys	0m1.387s

real	0m3.791s
user	0m43.662s
sys	0m1.340s

real	0m3.748s
user	0m43.290s
sys	0m1.284s

real	0m3.765s
user	0m43.465s
sys	0m1.289s

real	0m3.801s
user	0m43.572s
sys	0m1.314s
*/

#include <stdio.h>
#include <stdlib.h>

void mm(double* a, double* b, double* c, int width)
{
 #pragma omp parallel for collapse(2)
 for (int i = 0; i < width; i++) {
    for (int j = 0; j < width; j++) {
      double sum = 0;
      #pragma omp parallel for
      for (int k = 0; k < width; k++) {
	    double x = a[i * width + k];
	    double y = b[k * width + j];
	    sum += x * y;
      }
      c[i * width + j] = sum;
    }
  }
}

int main()
{
  int width = 2000;
  double *a = (double*) malloc (width * width * sizeof(double));
  double *b = (double*) malloc (width * width * sizeof(double));
  double *c = (double*) malloc (width * width * sizeof(double));
  
  #pragma omp parallel for collapse(2)
  for(int i = 0; i < width; i++) {
    for(int j = 0; j < width; j++) {
      a[i*width+j] = i;
      b[i*width+j] = j;
      c[i*width+j] = 0;
    }
  }

  mm(a,b,c,width);

  //  for(int i = 0; i < width; i++) {
  //  for(int j = 0; j < width; j++) {
  //    printf("\n c[%d][%d] = %f",i,j,c[i*width+j]);
  //  }
  // }
}
