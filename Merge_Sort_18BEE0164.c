/* 	Name - Advait Marathe	
	Reg - 18BEE0164			*/

#include<stdio.h>
#include<process.h>
#include<stdlib.h>
#include<sys/time.h>

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
		
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = 0;
	j = 0;
	k = l;
	
	while (i < n1 && j < n2) 
	{
		if (L[i] <= R[j]) 
		{
			arr[k] = L[i];
			i++;
		}
		
		else 
		{
			arr[k] = R[j];
			j++;
		}
		
		k++;
	}

	while (i < n1) 
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) 
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void print(int A[], int start, int end)
{
	int i;
	for (i = start; i <= end; i++)
		printf(" %d ", A[i]);
}

void merge_sort(int arr[], int l, int r)
{
	if (l < r) 
	{
		int m = l + (r - l) / 2;
		merge_sort(arr, l, m);
		merge_sort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

int main()
{
	struct timespec start, end;
	
	printf("\n ***** NAME - ADVAIT MARATHE *****\n");
	printf("\n ***** REG -  18BEE0164      *****\n");
	printf("\n *****     MERGE SORT        *****\n");
	
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
	merge_sort(arr, 0, n - 1);
	clock_gettime(CLOCK_MONOTONIC, &end);

	printf("\n Sorted array is - ");
	print(arr, 0, n - 1);
	
	double time_elapsed = (end.tv_sec - start.tv_sec) * 1e9 + end.tv_nsec - start.tv_nsec;
	printf("\n\n Merge sort took %f nanoseconds to execute. \n", time_elapsed);
	return 0;
}
