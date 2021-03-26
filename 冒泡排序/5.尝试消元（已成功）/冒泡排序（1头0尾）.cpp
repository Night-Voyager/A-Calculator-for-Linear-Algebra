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
    int i, j, k, l, m, n, p;
	float temp;

	m = (int)A[0][0];
	n = (int)A[0][1];

	for (l=1; l<m && l<n ; l++)
	{
	    for (i=l; i<m; i++)
		{
			for (j=l; j<m; j++)
			{
				if(A[j][l] > A[j+1][l])
				{
					for (k=l; k<=n; k++)
					{
						temp = A[j][k];
						A[j][k] = A[j+1][k];
						A[j+1][k] = temp;
					}
				}
			}
		} //对所有项从小到大排，负数在前，正数在后
		//(<0, 0, 0.x, 1, >1)

		for (i=l, p=0; i<=m; i++)
		{
			if (A[i][l]<0)
				p++;
		} //数出负数个数

		for (i=p+l; i<m; i++)
		{
		    for (j=p+l; j<m; j++)
			{
				if(A[j][l] < A[j+1][l])
				{
					for (k=l; k<=n; k++)
					{
						temp = A[j][k];
						A[j][k] = A[j+1][k];
						A[j+1][k] = temp;
					}
		        }
			}
		} //对非负项从大到小排，负数留在最前，0被排在最后
		//(<0, >1, 1, 0.x, 0)

		for (i=m, p=0; A[i][1]!=1 && i>=1; i--, p++)
			;//数出[0, 1)的数的个数

		for (i=l; i<=(m-l+1-p)/2; i++)
		{
			for (k=l; k<=n; k++)
			{
				temp = A[i][k];
				A[i][k] = A[m-p-i+1][k];
				A[m-p-i+1][k] = temp;
			}
		}//翻转
		//(1, >1, <0, 0.x, 0)

		for (i=l+1; i<=m; i++)
		{
			for (j=n; j>=l; j--)
			{
				A[i][j] = A[i][j]-A[l][j]*A[i][l]/A[l][l];
			}
		}//消元
	}
		return(A);
}