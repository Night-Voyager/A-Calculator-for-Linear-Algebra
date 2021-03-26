#ifndef INVERSE
#define INVERSE

#ifndef MAIN_FUNTION
#define MAIN_FUNTION
#define INVERSE_OK
#endif

#include "..\adjoint\adjoint.cpp"

float **inverse(float **);

#ifdef INVERSE_OK
void main()
{
	putmatrix( inverse( getmatrix() ) );
}
#endif

float **inverse(float **A)
{
	int m, n, i, j;
	m = (int)A[0][0];
	n = (int)A[0][1];

	if (m==n)
	{
		float **B;
		B = adj(A);

		float c;
		c = det(A);

		for (i=1; i<=m; i++)
		{
			for (j=1; j<=n; j++)
			{
				B[i][j]/=c;
			}
		}

		return (B);
	}
	else
		return (NULL);
}

#endif