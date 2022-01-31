/*	Name - Advait Marathe
	Reg - 18BEE0164			*/

#include<stdio.h>
#include<math.h>

#define N 25

float determinant(float [][N], int);
void cofactor(float [][N], int);
void transpose(float [][N], float [][N], int);

int main()
{
	printf("\n ***** NAME - ADVAIT MARATHE *****\n");
	printf("\n ***** REG -  18BEE0164      *****\n");
	printf("\n ***** Matrix Inversion      *****\n");
	
	float a[N][N], d;
  	int i, j, k;
  	printf("\n Enter the order of the Matrix - ");
  	scanf("%d", &k);
  	printf("\n Enter the elements for Matrix - \n");
	for(i = 0; i < k; i++)
	{
		for(j = 0; j < k; j++)
		{
			printf(" Enter the element [%d][%d] - ",i+1, j+1);
			scanf("%f", &a[i][j]);
		}
	}
  	d = determinant(a, k);
  	if (d == 0)
   		printf("\n!!!!! INVERSE NOT POSSIBLE !!!!!\n");
  	else
   		cofactor(a, k);
}

float determinant(float a[N][N], int k)
{
  	float s = 1, det = 0, b[N][N];
  	int i, j, m, n, c;
  	if (k == 1)
    {
     	return (a[0][0]);
    }
  	else
    {
     	det = 0;
     	for (c = 0; c < k; c++)
       	{
        	m = 0;
        	n = 0;
        	for (i = 0; i < k; i++)
          	{
            	for (j = 0; j < k; j++)
              	{
                	b[i][j] = 0;
                	if (i != 0 && j != c)
                 	{
                   		b[m][n] = a[i][j];
                   		if (n < (k - 2))
                    		n++;
                   		else
                    	{
                     		n = 0;
                     		m++;
                     	}
                   }
               }
             }
          	det = det + s * (a[0][c] * determinant(b, k - 1));
          	s = -1 * s;
        }
    }
    return (det);
}
 
void cofactor(float num[N][N], int k)
{
 	float b[N][N], fac[N][N];
 	int p, q, m, n, i, j;
 	for (q = 0; q < k; q++)
 	{
   		for (p = 0; p < k; p++)
    	{
     		m = 0;
     		n = 0;
     		for (i = 0; i < k; i++)
     		{
       			for (j = 0;j < k; j++)
        		{
          			if (i != q && j != p)
          			{
            			b[m][n] = num[i][j];
            			if (n < (k - 2))
             				n++;
            			else
             			{
               				n = 0;
               				m++;
               			}
            		}
        		}
      		}
      		fac[q][p] = pow(-1, q + p) * determinant(b, k - 1);
    	}
  	}
  	transpose(num, fac, k);
}
 
void transpose(float num[N][N], float fac[N][N], int k)
{
	int i, j;
  	float b[N][N], inverse[N][N], d;
 
	printf("\n <<<<< INPUT MATRIX >>>>>\n\n");
 
   	for (i = 0;i < k; i++)
   	{
     	for (j = 0;j < k; j++)
       	{
         	printf(" %0.4f ", num[i][j]);
        }
    	printf("\n");
	} 
  	
	for (i = 0; i < k; i++)
    {
     	for (j = 0; j < k; j++)
       	{
         	b[i][j] = fac[j][i];
        }
    }
    
    printf("\n <<<<< ADJOINT OF MATRIX >>>>>\n\n");
 
   	for (i = 0; i < k; i++)
   	{
     	for (j = 0; j < k; j++)
       	{
         	printf(" %0.4f ", b[i][j]);
        }
    	printf("\n");
	}
    
  	d = determinant(num, k);
  	for (i = 0; i < k; i++)
    {
     	for (j = 0; j < k; j++)
       	{
        	inverse[i][j] = b[i][j] / d;
        }
    }
    
    printf("\n DETERMINANT - %0.4f \n", d);
    
   	printf("\n <<<<< INVERSE OF MATRIX >>>>>\n\n");
 
   	for (i = 0; i < k; i++)
   	{
     	for (j = 0; j < k; j++)
       	{
         	printf(" %0.4f ", inverse[i][j]);
        }
    	printf("\n");
	}
}
