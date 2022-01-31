/* 	Name - Advait Marathe	
	Reg - 18BEE0164			*/

#include<stdio.h>
#include<process.h>
#include<stdlib.h>
#include<sys/time.h>

int get_pivot(int arr[], int lb, int ub)
{
	int pivot = arr[lb];
	int start = lb, end = ub;
	
	while(start < end)
	{
		while(arr[start] <= pivot)
		{
			start++;
		}
		
		while(arr[end] > pivot)
		{
			end--;
		}
		
		if(start < end)
		{
			int tmp = arr[start];
			arr[start] = arr[end];
			arr[end] = tmp;
		}
	}
	
	int fin_tmp = arr[end];
	arr[end] = arr[lb];
	arr[lb] = fin_tmp;
	
	return end;
}

void print(int A[], int start, int end)
{
	int i;
	for (i = start; i <= end; i++)
		printf(" %d ", A[i]);
}

void quick_sort(int arr[], int lb, int ub)
{
	if(lb < ub)
	{
		int pivot = get_pivot(arr, lb, ub);
		quick_sort(arr, lb, pivot-1);
		quick_sort(arr, pivot+1, ub);
	}
}

int main()
{
	
	struct timespec start, end;
	
	printf("\n ***** NAME - ADVAIT MARATHE *****\n");
	printf("\n ***** REG -  18BEE0164      *****\n");
	printf("\n *****     QUICK SORT        *****\n");
	
	int n;
	printf("\n Enter the size of array - ");
	scanf("%d", &n);
	
	int arr[n], i;
	for(i = 0; i < n; i++)
	{
		printf("\n Enter the element %d - ", i+1);
		scanf("%d", &arr[i]);
	}
	
	printf("\n Given array is - ");
	print(arr, 0, n - 1);
	printf("\n");
	
	clock_gettime(CLOCK_MONOTONIC, &start);
	quick_sort(arr, 0, n - 1);
	clock_gettime(CLOCK_MONOTONIC, &end);

	printf("\n Sorted array is - ");
	print(arr, 0, n - 1);
	
	double time_elapsed = (end.tv_sec - start.tv_sec) * 1e9 + end.tv_nsec - start.tv_nsec;
	printf("\n\n Quick sort took %f nanoseconds to execute. \n", time_elapsed);
	return 0;
}
