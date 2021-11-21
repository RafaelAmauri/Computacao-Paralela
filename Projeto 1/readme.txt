Segmentação de imagem usando k-means paralelo

COMO RODAR O PROGRAMA

g++ main.c -O3 -fopenmp
./a.out

COMO O PROGRAMA FUNCIONA

O algoritmo k-means (ou kmeans) é utilizado para repartir N dados entre K clusters, onde cada dado N 
é atribuído a um cluster, baseado na média mais próxima.

A implementação de k-means escolhida pelo grupo foi feita para ser utilizada em segmentação de imagens. 
Segmentação de imagens com k-means funciona ao agrupar os pixels da foto por cor a cada um dos clusters,
o que gera como resultado uma imagem com apenas K cores. Possíveis áreas de aplicação desse programa são
Computer Vision, uma forma rudimentar de facilitação de compressão de imagens e highlighting de formas e objetos.

Modificações feitas no código:

main.cpp

* Mudado a forma como o programa calcula tempo, usando omp_get_wtime
  (linha 86,88,92,94)

kmeans_omp.c

*adicionado diretivas nas linhas
 - 28
 - 56
 - 69
 
Repositório original:
https://github.com/rushimg/kmeans_imageSegmentation

