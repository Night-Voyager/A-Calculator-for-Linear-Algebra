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
    int i, j, k, m, n, p;
	float temp;

	m = (int)A[0][0];
	n = (int)A[0][1];

    for (i=1; i<m; i++)
	{
        for (j=1; j<m; j++)
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
	} //对所有项从小到大排，负数在前，正数在后
	//(<0, 0, 0.x, 1, >1)

	for (i=1, p=0; i<=m; i++)
	{
		if (A[i][1]<0)
			p++;
	} //数出负数个数

	for (i=p+1; i<m; i++)
	{
        for (j=p+1; j<m; j++)
        {
            if(A[j][1] < A[j+1][1])
            {
				for (k=1; k<=n; k++)
				{
					temp = A[j][k];
					A[j][k] = A[j+1][k];
					A[j+1][k] = temp;
				}
            }
        }
	} //对非负项从大到小排，负数留在最前，0被排在最后
	//(<0, >1, 1, 0.x, 0)

	for (i=m, p=0; A[i][1]!=1; i--, p++)
		;//数出[0, 1)的数的个数

	for (i=1; i<=(m-p)/2; i++)
	{
		for (k=1; k<=n; k++)
		{
			temp = A[i][k];
			A[i][k] = A[m-p-i+1][k];
			A[m-p-i+1][k] = temp;
		}
	}//翻转
	//(1, >1, <0, 0.x, 0)

	for (i=2; i<=m; i++)
	{
		for (j=n; j>=1; j--)
		{
			A[i][j] = A[i][j]-A[1][j]*A[i][1]/A[1][1];
		}
	}//消元

	return(A);
}