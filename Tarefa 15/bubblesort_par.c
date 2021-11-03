// Complexidade no modelo RAM: O(N^2)
// Complexidade no modelo PRAM: O(N)

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define SIZE 10000

void swap(int *a, int *b);

void bubblesort(int arr[], int size);

int main()
{
	int a[SIZE];
	
	for(int i = SIZE; i > 0; i--)
	{
		a[SIZE-i] = i;
	}

    for(int i = 0; i < SIZE; i++)
		printf("%d ", a[i]);

    printf("\n\n\n");


    bubblesort(a, SIZE);

	for(int i = 0; i < SIZE; i++)
		printf("%d ", a[i]);

	return 0;
}


void swap(int *a, int *b)
{
	int aux = *a;
	*a = *b;
	*b = aux;
}


void bubblesort(int arr[], int size)
{
    int i, j, aux;

    for(i = 0; i < size-1; i++)
    {
        aux = i % 2;
        #pragma omp parallel for
        for(j = aux; j < size-1; j++) 
        {
            if(arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}