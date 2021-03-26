#ifndef ELIMINATION
#define ELIMINATION

float **Gaussian(float **, int);

#ifndef MAIN_FUNTION
#define MAIN_FUNTION

#include "..\..\matrix.h"

void main()
{
	putmatrix(Gaussian(getmatrix(), 1));
}
#endif

float **Gaussian(float **A, int x)
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
		} //���������С�����ţ�������ǰ�������ں�
		//(<0, 0, 0.x, 1, >1)

		for (i=l, p=0; i<=m; i++)
		{
			if (A[i][l]<0)
				p++;
		} //������������

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
		} //�ԷǸ���Ӵ�С�ţ�����������ǰ��0���������
		//(<0, >1, 1, 0.x, 0)

		for (i=m, p=0; A[i][1]!=1 && i>=1; i--, p++)
			;//����[0, 1)�����ĸ���

		for (i=l; i<=(m-l+1-p)/2; i++)
		{
			for (k=l; k<=n; k++)
			{
				temp = A[i][k];
				A[i][k] = A[m-p-i+1][k];
				A[m-p-i+1][k] = temp;
			}
		}//��ת
		//(1, >1, <0, 0.x, 0)

		if (A[l][l])
		{
			for (i=l+1; i<=m; i++)
			{
				for (j=n; j>=l; j--)
				{
					A[i][j] = A[i][j]-A[l][j]*A[i][l]/A[l][l];
				}
			}//��Ԫ
		}
	}

	for (i=1; i<=m; i++)
	{
		for (k=1; A[i][k]==0 && k<=n; k++)
			;
		if (k<=n)
			for (j=n; j>=k; j--)
				A[i][j]/=A[i][k];
	}

	switch(x)
	{
	case 1:
		return (A);
	case 2:
		for (l=m; l>1; l--)
		{
			for (p=1; A[l][p]==0 && p<=n; p++)
				;
			if (p<=n)
				for (i=l-1; i>=1; i--)
					for (j=n; j>=1; j--)
						A[i][j] = A[i][j]-A[l][j]*A[i][p]/A[l][p];
		}
		return (A);
	case 3:
		for (l=m; l>1; l--)
		{
			for (p=1; A[l][p]==0 && p<n; p++)
				;
			if (p<n)
				for (i=l-1; i>=1; i--)
					for (j=n; j>=1; j--)
						A[i][j] = A[i][j]-A[l][j]*A[i][p]/A[l][p];
		}
		return (A);
	default:
		printf("\n��������\n"
			"Incorrect input.\n");
		return NULL;
	}
}

#endif