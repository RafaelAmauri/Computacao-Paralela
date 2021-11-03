#include <stdio.h>
#include <stdlib.h>

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
	for(int i = 0; i < size-1; i++)
	{
  		for(int j = 0; j < size-i-1; j++) 
    	{
			if(arr[j] > arr[j+1])
			{
    			swap(&arr[j], &arr[j+1]);
			}
		}
	}
}
