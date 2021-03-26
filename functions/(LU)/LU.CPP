#ifndef TRIANGULAR_FACTORIZATION
#define TRIANGULAR_FACTORIZATION

void LU(float **);

#ifndef MAIN_FUNTION
#define MAIN_FUNTION

#include "..\..\matrix.h"

void main()
{
	LU(getmatrix());
}
#endif

void LU(float **A)
{
	if ( A[0][0]==A[0][1] && A[0][0]>=1 )
	{
		int n=(int)A[0][0];
		float f=1;
		int i, j, k;
		for (i=1; i<=n; i++)
			f = f*A[i][i];
		if (f)
		{
			float **L, **U;
			L = (float **)malloc( (n+1)*sizeof(float) );
			U = (float **)malloc( (n+1)*sizeof(float) );
			for (i=0; i<=n; i++)
			{
				L[i] = (float *)malloc( (n+1)*sizeof(float) );
				U[i] = (float *)malloc( (n+1)*sizeof(float) );
			}
			L[0][0] = L[0][1] = U[0][0] = U[0][1] = (float)n;
			for (i=1; i<=n; i++)
			{
				for (j=1; j<=n; j++)
				{
					U[i][j] = A[i][j];
					if (i==j)
						L[i][j] = 1;
					else
						L[i][j] = 0;
				}
			}
			for (i=1; i<n; i++)
			{
				for (k=i+1; k<=n; k++)
				{
					for (j=n; j>=i; j--)
					{
						
						U[k][j]-=U[i][j]*U[k][i]/U[i][i];
					}
				}
			}
			printf("\nA = LU\n");
			printf("L = \n");
			putmatrix( mul(A, inverse(U)) );
			printf("U = \n");
			putmatrix(U);
		}
		else
			printf("\n该矩阵不可三角分解。\n"
			"This matrix can not be triangular factorized.\n");
	}
	else
		printf("\n该矩阵不可三角分解。\n"
		"This matrix can not be triangular factorized.\n");
}

#endif