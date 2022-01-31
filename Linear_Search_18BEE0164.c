/*	Name - Advait Marathe
	Reg - 18BEE0164			*/

#include<stdio.h>
#include<process.h>
#include<stdlib.h>
#include<sys/time.h>

int linear_search(int arr[], int key, int start, int end)
{
	if(arr[start] == key)
		return start;
	
	if(start == end)
		return -1;
		
	linear_search(arr, key, start+1, end);
}

int main()
{
	int i;
	struct timespec start, end;
	
	printf("\n ***** NAME - ADVAIT MARATHE *****\n");
	printf("\n ***** REG -  18BEE0164      *****\n");
	printf("\n *****    LINEAR SEARCH      *****\n");
	
	int arr[] = {45, 23, 89, 20, 67, 22, 19, 10, 60, 24, 90, 76, 52, 4, 98, 56};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	int ele;
	printf("\n Enter the element to be searched - ");
	scanf("%d", &ele);
		
	clock_gettime(CLOCK_MONOTONIC, &start);
	
	int pos = linear_search(arr, ele, 0, size-1);
	
	clock_gettime(CLOCK_MONOTONIC, &end);
		
	double time_elapsed = (end.tv_sec - start.tv_sec) * 1e9 + end.tv_nsec - start.tv_nsec;
		
	if(pos == -1)
		printf("\n Element not found in the list.");
		
	else
		printf("\n Element found at position at %d", pos+1);
		
	printf("\n\n Linear Search took %f nanoseconds to execute. \n", time_elapsed);
	
	return(0);
}
