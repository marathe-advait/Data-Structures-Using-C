/*	Name - Advait Marathe
	Reg - 18BEE0164			*/

#include<stdio.h>
#include<process.h>
#include<stdlib.h>
#include<sys/time.h>

void counting_sort(int array[], int size) 
{
	int output[size];
	int max = array[0], i;
	
	for (i = 1; i < size; i++) 
	{
		if (array[i] > max)
			max = array[i];
	}
	
	int count[max+1];
	for (i = 0; i <= max; ++i) 
		count[i] = 0;
	
	for (i = 0; i < size; i++) 
		count[array[i]]++;
	
	for (i = 1; i <= max; i++) 
		count[i] += count[i - 1];
	
	for (i = size - 1; i >= 0; i--) 
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	
	for (i = 0; i < size; i++)
    	array[i] = output[i];
    	
    printf("\n The sorted array is - ");
    for (i = 0; i < size; i++)
    	printf(" %d ", array[i]);
    	
}

int main()
{
	struct timespec start, end;
	
	printf("\n ***** NAME - ADVAIT MARATHE *****\n");
	printf("\n ***** REG -  18BEE0164      *****\n");
	printf("\n *****   COUNTING SORT       *****\n");
	
	int n;
	printf("\n Enter the size of array - ");
	scanf("%d", &n);
	
	int arr[n], i;
	for(i = 0; i < n; i++)
	{
		printf("\n Enter the element %d - ", i+1);
		scanf("%d", &arr[i]);
	}
	
	printf("\n\n The given array is - ");
	for(i = 0; i < n; i++)
	{
		printf(" %d ", arr[i]);
	}
	
	clock_gettime(CLOCK_MONOTONIC, &start);
	
	counting_sort(arr, n);
	
	clock_gettime(CLOCK_MONOTONIC, &end);
		
	double time_elapsed = (end.tv_sec - start.tv_sec) * 1e9 + end.tv_nsec - start.tv_nsec;
	
	printf("\n\n Counting sort took %f nanoseconds to execute. \n", time_elapsed);
	
	return(0);
}
