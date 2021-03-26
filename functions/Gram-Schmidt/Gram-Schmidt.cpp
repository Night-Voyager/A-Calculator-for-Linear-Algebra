#ifndef GRAM_SCHMIDT
#define GRAM_SCHMIDT

void GramSchmidt(float **, int);

#ifndef MAIN_FUNTION
#define MAIN_FUNTION

#include <stdio.h>
#include <stdlib.h>
#include "..\..\matrix.h"

void main()
{
	GramSchmidt(getmatrix(), 1);
	GramSchmidt(getmatrix(), 2);
}
#endif

void GramSchmidt(float **A, int x)
{
	int m, n, i, j, k;
	float **Q, **R, **tem1, **tem2;

	m = (int)A[0][0];
	n = (int)A[0][1];

	Q = (float **)malloc( (m+1)*sizeof(float) );
	R = (float **)malloc( (n+1)*sizeof(float) );
	tem1 = (float **)malloc( (m+1)*sizeof(float) );
	tem2 = (float **)malloc( (m+1)*sizeof(float) );

	for (i=0; i<=m; i++)
		Q[i] = (float *)malloc( (n+1)*sizeof(float) );
	for (i=0; i<=n; i++)
		R[i] = (float *)malloc( (n+1)*sizeof(float) );
	for (i=0; i<=m; i++)
	{
		tem1[i] = (float *)malloc( 2*sizeof(float) );
		tem2[i] = (float *)malloc( 2*sizeof(float) );
	}

	for (j=0; j<=n; j++)
	{
		for (i=0; i<=m; i++)
			Q[i][j] = 0;
		for (i=0; i<=n; i++)
			R[i][j] = 0;
	}

	Q[0][0] = (float)m;
	Q[0][1] = (float)n;
	R[0][0] = R[0][1] = (float)n;
	tem1[0][0] = tem2[0][0] = (float)m;
	tem1[0][1] = tem2[0][1] = 1;

	for (k=1; k<=n; k++)
	{
		for (i=1; i<=m; i++)
			tem1[i][1] = A[i][k];
		R[k][k] = Euclen(tem1);
		for (i=1; i<=m; i++)
			Q[i][k] = A[i][k]/R[k][k];
		for (j=k+1; j<=n; j++)
		{
			for (i=1; i<=m; i++)
			{
				tem1[i][1] = Q[i][k];
				tem2[i][1] = A[i][j];
			}
			R[k][j] = inner(tem1, tem2);
			for (i=1; i<=m; i++)
				A[i][j]-=R[k][j]*Q[i][k];
		}
	}
	
	switch(x)
	{
	case 1:
		printf("\n该空间的一个正交基为\n"
			"An orthonormal for the space is\n");
		putmatrix(Q);
		break;
	case 2:
		printf("\nA = QR\n");
		printf("\nQ = \n");
		putmatrix(Q);
		printf("\nR = \n");
		putmatrix(R);
		break;
	default:
		printf("\n输入有误。\n"
			"Incorrect input.\n");
		break;
	}

	for (i=0; i<=m; i++)
		free(Q[i]);
	for (i=0; i<=n; i++)
		free(R[i]);
	free (Q);
	free (R);
	for (i=0; i<=m; i++)
	{
		free(tem1[i]);
		free(tem2[i]);
	}
	free (tem1);
	free (tem2);
}
#endif