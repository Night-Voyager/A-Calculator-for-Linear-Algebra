#include <stdio.h>
#include "matrixio.h"

float **bubble_sort(float **A);

void main()
{
	float **A;
	A = getmatrix();
	putmatrix(bubble_sort(A));
}

float **bubble_sort(float **A)
{
    int i, j, k, m, n;
	float temp;

	m = (int)A[0][0];
	n = (int)A[0][1];

    for (i=1; i<=m-1; i++)
	{
        for (j=1; j<=m-i; j++)
        {
            if(A[j][1] > A[j+1][1])
            {
				for (k=1; k<=n; k++)
				{
					temp = A[j][k];
					A[j][k] = A[j+1][k];
					A[j+1][k] = temp;
				}
            }
        }
	}
	return(A);
}