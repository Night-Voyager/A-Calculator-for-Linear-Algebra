#ifndef ARITHMETIC
#define ARITHMETIC

#include "../matrixio/matrixio.h"

float **add(float **, float **);
float **sub(float **, float **);
float **mul(float **, float **);
float **scmul(float, float **);

#ifndef MAIN_FUNTION
void main()
{
	printf("+, -, *, /.\n");
	char c;
	c = getchar();
	switch (c)
	{
	case '+':
		float **A;
		A = getmatrix();
		float **B;
		B = getmatrix();
		putmatrix( add(A, B) );
		break;
	case '-':
		float **C;
		C = getmatrix();
		float **D;
		D = getmatrix();
		putmatrix( sub(C, D) );
		break;
	case '*':
		float **E;
		E = getmatrix();
		float **F;
		F = getmatrix();
		putmatrix( mul(E, F) );
		break;
	case '/':
		float **G;
		float g;
		G = getmatrix();
		scanf("%f", &g);
		putmatrix( scmul(g, G) );
		break;
	}
}
#endif

float **add(float **A, float **B)
{
	int ma, na, mb, nb;
	ma = (int)A[0][0];
	na = (int)A[0][1];
	mb = (int)B[0][0];
	nb = (int)B[0][1];

	if ( ma==mb && na==nb )
	{
		int m=ma, n=nb, i, j;
		float **C;
		C = (float **)malloc( (m+1)*sizeof(float) );
		for (i=0; i<=m; i++)
		{
			C[i] = (float *)malloc( (n+1)*sizeof(float) );
		}
		C[0][0] = (float)m;
		C[0][1] = (float)n;

		for (i=1; i<=m; i++)
		{
			for (j=1; j<=n; j++)
			{
				C[i][j] = A[i][j] + B[i][j];
			}
		}

		return (C);
	}
	else
	{
		printf("这两个矩阵不能相加。\n"
			"These two matrices cannot be added together.\n");
		return (NULL);
	}
}

float **sub(float **A, float **B)
{
	int ma, na, mb, nb;
	ma = (int)A[0][0];
	na = (int)A[0][1];
	mb = (int)B[0][0];
	nb = (int)B[0][1];

	if ( ma==mb && na==nb )
	{
		int m=ma, n=nb, i, j;
		float **C;
		C = (float **)malloc( (m+1)*sizeof(float) );
		for (i=0; i<=m; i++)
		{
			C[i] = (float *)malloc( (n+1)*sizeof(float) );
		}
		C[0][0] = (float)m;
		C[0][1] = (float)n;

		for (i=1; i<=m; i++)
		{
			for (j=1; j<=n; j++)
			{
				C[i][j] = A[i][j] - B[i][j];
			}
		}

		return (C);
	}
	else
	{
		printf("这两个矩阵不能相减。\n"
			"These two matrices cannot be subtracted.\n");
		return (NULL);
	}
}

float **mul(float **A, float **B)
{
	int ma, na, mb, nb;
	ma = (int)A[0][0];
	na = (int)A[0][1];
	mb = (int)B[0][0];
	nb = (int)B[0][1];

	if ( na==mb )
	{
		int m=ma, n=nb, i, j;
		float **C;
		C = (float **)malloc( (m+1)*sizeof(float) );
		for (i=0; i<=m; i++)
		{
			C[i] = (float *)malloc( (n+1)*sizeof(float) );
		}

		for (i=0; i<=m; i++)
		{
			for (j=0; j<=n; j++)
			{
				C[i][j] = 0;
			}
		}

		C[0][0] = (float)m;
		C[0][1] = (float)n;
		
		for(i=1; i<=m; i++)
		{
			for(j=1; j<=n; j++)
			{
				for(int k=1; k<=na; k++)
				{
					C[i][j]+=A[i][k]*B[k][j]; 
				}
			}
		}

		return (C);
	}
	else
	{
		printf("这两个矩阵不能相乘。\n"
			"These two matrices cannot be multiplied.\n");
		return (NULL);
	}
}

float **scmul(float a, float **A)
{
	int m, n, i, j;

	m = (int)A[0][0];
	n = (int)A[0][1];

	float **B;
	B = (float **)malloc( (m+1)*sizeof(float) );
	for (i=0; i<=m; i++)
	{
		B[i] = (float *)malloc( (n+1)*sizeof(float) );
	}
	B[0][0] = (float)m;
	B[0][1] = (float)n;

	for (i=1; i<=m; i++)
	{
		for (j=1; j<=n; j++)
		{
			B[i][j] = a*A[i][j];
		}
	}

	return (B);
}

#endif