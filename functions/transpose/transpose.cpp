#ifndef TRANSPOSE
#define TRANSPOSE

#include "../matrixio/matrixio.h"

float **transpose(float **);

#ifndef MAIN_FUNTION
void main()
{
	putmatrix( transpose( getmatrix() ) );
}
#endif

float **transpose(float **A)
{
	float **B;
	int m, n, i, j;

	m = (int)A[0][0];
	n = (int)A[0][1];

	B = (float **)malloc( (n+1)*sizeof(float) );

	for (i=0; i<=n; i++)
	{
		B[i] = (float *)malloc( (m+1)*sizeof(float) );
	}
	
	B[0][0] = (float)n;
	B[0][1] = (float)m;

	for (i=1; i<=n; i++)
	{
		for (j=1; j<=m; j++)
		{
			B[i][j] = A[j][i];
		}
	}

	return (B);
}

#endif