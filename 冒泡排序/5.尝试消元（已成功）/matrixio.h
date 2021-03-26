/*********************************************************

ע�� ATTITION

1.ʹ��ʱ��ͷ�ļ�ʱ�ڳ���ͷ���ϣ�
  Add this at the beginning of the programme when using this header file:
	  #include "matrixio.h"

2.�������еľ���Ӧ����Ϊָ�򸡵���ָ���ָ�룬������ʾ��
  Every matrics in the main funtion should be declared to be a pointer to pointer of float type as below:
	  float **MatrixName;

3.��������е��㡢һ���ֵ�ֱ�Ϊ�����������������
  The values of the zeroth and first terms in the zeroth row of a matrix are the number of rows and columns of the matrix respectively.

*********************************************************/

#ifndef MATRIXIO//�Է�ͷ�ļ����ظ�ʹ�á�
#define MATRIXIO//In case of the header file is repeated included.

/*���������ͷ�ļ�*/
/*Include needed header files*/
#include <stdio.h>
#include <stdlib.h>

/*���ڶ�ȡһ������ĺ���*/
/*funtion to get a matrix*/
float **getmatrix()
{
	float **matrix;
	//��matrix��������Ϊһ��ָ��ָ���ָ�롣The "matrix" is declared to be a pointer to pointer.
	//�������ԭ���ں��������The reason to do like this will be given later.

	int m, n, i, j;
	//�±�ʹ����ѭ���Դ������ϰ�ߡ�Subscripts' usage follows the conventions of linear algebra.

	printf("������������Please enter the number of rows.\n");
	scanf("%d", &m);

	printf("������������Please enter the number of columns.\n");
	scanf("%d", &n);

	matrix = (float **)malloc( (m+1)*sizeof(float) );
	//Ϊ�������������һ��С���ڴ�ռ䡣Allocate an area of memory with size of the number of rows plus one for the matrix.
	//��һ����Ϊ�е����С�Plusing one is because of the zeroth row.

	for (i=0; i<=m; i++)
	{
		matrix[i] = (float *)malloc( (n+1)*sizeof(float) );
		//Ϊ�����ÿһ�з���������һ��С���ڴ�ռ䡣
		//Allocate an area of memory with size of the number of columns plus one for every row of the matrix.
		//��һ����Ϊ�е����С�
		//Plusing one is because of the zeroth column.
		//����ռ�ķ�ʽ���ǡ�matrix����һ��ָ��ָ���ָ���ԭ��
		//The way to allocate area is the reason why "matrix" is a pointer to pointer.
	}

	matrix[0][0] = (float)m; //���������ڵ����е������С�Save the number of rows in the zeroth term of the zeroth row.
	matrix[0][1] = (float)n; //���������ڵ����е�һ���С�Save the number of columns in the first term of the zeroth row.
	//�������ڱ�ĺ�����ȡ�����������������This makes it easier for other functions to read the number of rows and columns of a matrix.

	printf("���������Please enter the matrix.\n");
	for (i=1; i<=m; i++)
	{
		for (j=1; j<=n; j++)
		{
			scanf("%f", &matrix[i][j] );
		}
	}

	return (matrix);
}

/*�������һ������ĺ���*/
/*funtion to put a matrix*/
void putmatrix(float **matrix)
{
	if (matrix!=NULL)
	{
		int m, n, i, j;

		m = (int)matrix[0][0]; //��ȡ��������Read the total number of rows of the matrix.
		n = (int)matrix[0][1]; //��ȡ��������Read the total unmber of columns of the matrix.

		for (i=1; i<=m; i++)
		{
			for (j=1; j<=n; j++)
			{
				printf("%4g ", matrix[i][j] );
			}
			putchar('\n'); //ÿ�����һ�л��С�Turn to a new column when a column is finished.
		}
	}
}

#endif