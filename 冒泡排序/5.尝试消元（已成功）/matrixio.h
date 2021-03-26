/*********************************************************

注意 ATTITION

1.使用时此头文件时在程序开头加上：
  Add this at the beginning of the programme when using this header file:
	  #include "matrixio.h"

2.主程序中的矩阵应声明为指向浮点类指针的指针，如下所示：
  Every matrics in the main funtion should be declared to be a pointer to pointer of float type as below:
	  float **MatrixName;

3.矩阵第零行第零、一项的值分别为矩阵的行数和列数。
  The values of the zeroth and first terms in the zeroth row of a matrix are the number of rows and columns of the matrix respectively.

*********************************************************/

#ifndef MATRIXIO//以防头文件被重复使用。
#define MATRIXIO//In case of the header file is repeated included.

/*引入所需的头文件*/
/*Include needed header files*/
#include <stdio.h>
#include <stdlib.h>

/*用于读取一个矩阵的函数*/
/*funtion to get a matrix*/
float **getmatrix()
{
	float **matrix;
	//“matrix”被声明为一个指向指针的指针。The "matrix" is declared to be a pointer to pointer.
	//如此做的原因将在后面给出。The reason to do like this will be given later.

	int m, n, i, j;
	//下标使用遵循线性代数里的习惯。Subscripts' usage follows the conventions of linear algebra.

	printf("请输入行数。Please enter the number of rows.\n");
	scanf("%d", &m);

	printf("请输入列数。Please enter the number of columns.\n");
	scanf("%d", &n);

	matrix = (float **)malloc( (m+1)*sizeof(float) );
	//为矩阵分配行数加一大小的内存空间。Allocate an area of memory with size of the number of rows plus one for the matrix.
	//加一是因为有第零行。Plusing one is because of the zeroth row.

	for (i=0; i<=m; i++)
	{
		matrix[i] = (float *)malloc( (n+1)*sizeof(float) );
		//为矩阵的每一行分配列数加一大小的内存空间。
		//Allocate an area of memory with size of the number of columns plus one for every row of the matrix.
		//加一是因为有第零列。
		//Plusing one is because of the zeroth column.
		//分配空间的方式就是“matrix”是一个指向指针的指针的原因。
		//The way to allocate area is the reason why "matrix" is a pointer to pointer.
	}

	matrix[0][0] = (float)m; //把行数存在第零行第零项中。Save the number of rows in the zeroth term of the zeroth row.
	matrix[0][1] = (float)n; //把列数存在第零行第一项中。Save the number of columns in the first term of the zeroth row.
	//这样便于别的函数读取矩阵的行数和列数。This makes it easier for other functions to read the number of rows and columns of a matrix.

	printf("请输入矩阵。Please enter the matrix.\n");
	for (i=1; i<=m; i++)
	{
		for (j=1; j<=n; j++)
		{
			scanf("%f", &matrix[i][j] );
		}
	}

	return (matrix);
}

/*用于输出一个矩阵的函数*/
/*funtion to put a matrix*/
void putmatrix(float **matrix)
{
	if (matrix!=NULL)
	{
		int m, n, i, j;

		m = (int)matrix[0][0]; //读取总行数。Read the total number of rows of the matrix.
		n = (int)matrix[0][1]; //读取总列数。Read the total unmber of columns of the matrix.

		for (i=1; i<=m; i++)
		{
			for (j=1; j<=n; j++)
			{
				printf("%4g ", matrix[i][j] );
			}
			putchar('\n'); //每输出完一行换行。Turn to a new column when a column is finished.
		}
	}
}

#endif