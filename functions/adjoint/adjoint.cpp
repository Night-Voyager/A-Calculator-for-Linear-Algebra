#ifndef ADJOINT
#define ADJOINT

#ifndef MAIN_FUNTION
#define MAIN_FUNTION
#define ADJOINT_OK
#endif

#include "..\determinant\determinant.cpp"
#include "..\transpose\transpose.cpp"

float **adj(float **);

#ifdef ADJOINT_OK
void main()
{
	putmatrix( adj( getmatrix() ) );
}
#endif

float **adj(float **A)
{
	int m, n, i, j;

	m = (int)A[0][0];
	n = (int)A[0][1];

	float **adjA;
	adjA = (float **)malloc( m*sizeof(float) );
	for (i=0; i<=m; i++)
	{
		adjA[i] = (float *)malloc( n*sizeof(float) );
	}

	adjA[0][0] = (float)m;
	adjA[0][1] = (float)n;

	for (i=1; i<=m; i++)
	{
		for (j=1; j<=n; j++)
		{
			adjA[i][j] = cofactor(A, i, j);
		}
	}

	return ( transpose(adjA) );
}

#endif