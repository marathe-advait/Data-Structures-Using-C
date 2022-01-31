/*	Name - Advait Marathe
	Reg - 18BEE0164			*/
	
#include<stdio.h>

void avgmatrix(float a[], int n)
{
	float res[n][n];
	int i, j, k;
	
	for(j = 0; j < n; j++)										//	T(n) = O(n)
	{
		res[j][j] = a[j];										//	T(n) = O(1)
	}
	
	for(i = 0; i < n; i++)										//	T(n) = O(n)
	{
		for(j = 0; j < n; j++)									//	T(n) = O(n)
		{
			if(i > j)											//	T(n) = O(1)
				res[i][j] = 0;									//	T(n) = O(1)
		}
	}
	
	for(i = 0; i < n; i++)										//	T(n) = O(n)
	{
		for(j = 0; j < n; j++)									// 	T(n) = O(n)
		{
			if(i < j)											//	T(n) = O(1)
			{
				res[i][j] = 0.0;								//	T(n) = O(1)
				for(k = i; k <= j; k++)							//	T(n) = i - j, considering worst case, T(n) = O(n)
					res[i][j] += a[k];							//	T(n) = O(1)
				
				res[i][j] /= (j - i + 1); 						//	T(n) = O(1)
			}
		}
	}
	
	printf("\n The Resultant Matrix Is - \n\n");				//	T(n) = O(1)
	
	for(i = 0; i < n; i++)										// 	T(n) = O(n)
	{
		for(j = 0; j < n; j++)									//	T(n) = O(n)	
		{
			printf(" %f\t", res[i][j]);							//	T(n) = O(1)
		}
		printf("\n");											//	T(n) = O(1)
	}
}

int main()
{
	int n, i;
	printf("\n Enter the size of array - ");					//	T(n) = O(1)
	scanf("%d", &n);											// 	T(n) = O(1)	
	
	float a[n];
	printf("\n Enter the array elements - \n");					//	T(n) = O(1)
	for( i= 0; i < n; i++)										//	T(n) = O(n)
	{
		printf(" Enter the element %d - ", (i+1));				//	T(n) = O(1)
		scanf("%f", &a[i]);										//	T(n) = O(1)
	}
	
	avgmatrix(a, n);
}
