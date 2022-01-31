/*	Name - Advait Marathe
	Reg - 18BEE0164			*/

#include<stdio.h>
#include<process.h>
#include<stdlib.h>
#include<sys/time.h>

void insertion_sort(int *arr, int n, int pass)
{
	int j, tmp;
	
	if(pass == n)
	{
		printf("\n\n The array is sorted.");
		return;
	}
	
	j = pass-1;
	tmp = arr[pass];
	
	while(j >= 0 && arr[j] > tmp)
	{
		arr[j+1] = arr[j];
		j = j-1;
	}
	
	arr[j+1] = tmp;
	
	printf("\n\n Array after Pass %d - ", pass);
	for(j = 0; j < n; j++)
	{
		printf(" %d ", arr[j]);
	}
	
	insertion_sort(arr, n, pass+1);
}

int main()
{
	struct timespec start, end;
	
	printf("\n ***** NAME - ADVAIT MARATHE *****\n");
	printf("\n ***** REG -  18BEE0164      *****\n");
	printf("\n *****   INSERTION SORT      *****\n");
	
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
	
	insertion_sort(arr, n, 1);
	
	clock_gettime(CLOCK_MONOTONIC, &end);
		
	double time_elapsed = (end.tv_sec - start.tv_sec) * 1e9 + end.tv_nsec - start.tv_nsec;
	
	printf("\n\n Insertion sort took %f nanoseconds to execute. \n", time_elapsed);
	
	return(0);
}
