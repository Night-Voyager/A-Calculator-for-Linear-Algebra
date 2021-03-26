#ifndef DETERMINANT
#define DETERMINANT

#include <math.h>
#include "..\matrixio\matrixio.h"

float det(float **);//行列式
float **minor(float **, int, int);//余子矩阵
float cofactor(float **, int, int);//代数余子式

#ifndef MAIN_FUNTION
void main()
{
	float **A;
	A = getmatrix();
	putmatrix(minor(A, 1, 1));
	printf("%g\n", det(A));
}
#endif

float det(float **A)
{
	int m, n, j;
	float det = 0;

	m = (int)A[0][0];
	n = (int)A[0][1];

	if (m!=n)
	{
		printf("\n这不是方阵。\n"
			"This is not a square matrix.");
		det = 0;
	}
	else if (m==1)
		det = A[1][1];
	else if (m==2)
		det = A[1][1]*A[2][2]-A[2][1]*A[1][2];
	else if (m==3)
		det = A[1][1]*A[2][2]*A[3][3] + A[1][2]*A[2][3]*A[3][1] + A[1][3]*A[2][1]*A[3][2]
			 -A[1][3]*A[2][2]*A[3][1] - A[1][1]*A[2][3]*A[3][2] - A[1][2]*A[2][1]*A[3][3];
	else
		for (j=1; j<=n; j++)
		{
			det+=A[1][j]*cofactor(A, 1, j);
		}

	return (det);
}

float cofactor(float **A, int i, int j)
{
	float Aij;
	Aij = (float)pow(-1, (i+j) )*det(minor(A, i, j));
	return (Aij);
}

float **minor(float **A, int i, int j)
{
	int m, n, x, y;
	m = (int)A[0][0];
	n = (int)A[0][1];

	float **M;
	M = (float **)malloc( m*sizeof(float) );
	for (x=0; x<=m; x++)
	{
		M[x] = (float *)malloc( n*sizeof(float) );
	}

	M[0][0] = (float)(m-1);
	M[0][1] = (float)(n-1);

	for (x=1; x<i; x++)
	{
		for (y=1; y<j; y++)
		{
			M[x][y] = A[x][y];
		}

		for (y=j+1; y<=n; y++)
		{
			M[x][y-1] = A[x][y];
		}
	}

	for (x=i+1; x<=m; x++)
	{
		for (y=1; y<j; y++)
		{
			M[x-1][y] = A[x][y];
		}

		for (y=j+1; y<=n; y++)
		{
			M[x-1][y-1] = A[x][y];
		}
	}

	return (M);
}

#endif