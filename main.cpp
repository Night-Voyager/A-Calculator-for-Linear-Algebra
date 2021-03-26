#define MAIN_FUNTION

#include "matrix.h"
#include <windows.h>

void main()
{
beginning:

	WelcomingInterface();

	int choice1, choice2, choice3;
	scanf("%d", &choice1);
	choice2=choice3=0;

	float **A, **B;

	int i, j;

funtion:
	switch (choice1)
	{
	case 0: //退出
		exit(0);
	case 1: //基础运算
		if (choice2==0)
		{
whatoperation:
			BasicOperation();
			scanf("%d", &choice2);
		}
		switch (choice2)
		{
		case 0: //退出
			exit(0);
		case 1: //和
			printf("\n对于第一个矩阵A:\n"
				"For the first matrix A:\n");
			A = getmatrix();
			printf("\n对于第二个矩阵B:\n"
				"For the second matrix B:\n");
			B = getmatrix();
			printf("\n这两个矩阵的和为\n"
				"The sum of these two matrices is\n"
				"A+B = \n");
			putmatrix( add(A, B) );
			break;
		case 2: //差
			printf("\n对于第一个矩阵A:\n"
				"For the first matrix A:\n");
			A = getmatrix();
			printf("\n对于第二个矩阵B:\n"
				"For the second matrix B:\n");
			B = getmatrix();
			printf("\n这两个矩阵的差为\n"
				"The difference between these two matrices is\n"
				"A-B = \n");
			putmatrix( sub(A, B) );
			break;
		case 3: //积
			if (choice3==0)
			{
whatproduction:
				Production();
				scanf("%d", &choice3);
			}
			switch (choice3)
			{
			case 0: //退出
				exit(0);
			case 1: //标量积
				float scalar;
				printf("\n请输入标量α的值。\n"
					"Please enter the value of the scalar α: ");
				scanf("%f", &scalar);
				printf("\n对于矩阵A:\n"
					"For the matrix A:\n");
				A = getmatrix();
				printf("\n该标量与矩阵的积为\n"
					"The production of the scalar and the matrix is\n"
					"αA = \n");
				putmatrix( scmul(scalar, A) );
				break;
			case 2: //矩阵积
				printf("\n对于第一个矩阵A:\n"
					"For the first matrix A:\n");
				A = getmatrix();
				printf("\n对于第二个矩阵B:\n"
					"For the second matrix B:\n");
				B = getmatrix();
				printf("\n这两个矩阵的积为\n"
					"The production of these two matrices is\n"
					"AB = \n");
				putmatrix( mul(A, B) );
				break;
			case 3: //内积
				printf("\n对于第一个向量x:\n"
					"For the first vector x:\n");
				A = getvector();
				printf("\n对于第二个向量B:\n"
					"For the second vector y:\n");
				B = getvector();
				printf("\n这两个向量的内积为\n"
					"The inner product of these two vectors is\n"
					"<x, y> = %g\n", inner(A, B) );
				break;
			case 4: //叉积
				printf("\n对于第一个向量x:\n"
					"For the first vector x:\n");
				A = getvector();
				printf("\n对于第二个向量B:\n"
					"For the second vector y:\n");
				B = getvector();
				printf("\n这两个向量的外积为\n"
					"The outer product of these two vectors is\n"
					"x×y = ");
				putvector( outer(A, B) );
				break;
			case 5: //回主界面
				goto beginning;
			default: //输入有误
				goto whatproduction;
			}
			break;
		case 4: //逆
			printf("\n对于矩阵A:\n"
				"For matrix A:\n");
			A = getmatrix();
			if (!det(A))
			{
				printf("\n这个矩阵没有逆矩阵。\n"
					"This matrix has no inverse.\n");
			}
			else
			{
				printf("\n这个矩阵的逆矩阵是\n"
					"The inverse of this matrix is\n"
					"A^(-1) = \n");
				putmatrix( inverse(A) );
			}
			break;
		case 5: //幂
			printf("\n对于矩阵A:\n"
				"For matrix A:\n");
			A = getmatrix();
			B = A;
			printf("\n请输入指数。Please enter the exponent.\n");
			scanf("%d", &j);
			for (i=1; i<j; i++)
			{
				B = mul(A, B);
			}
			printf("A^%d = \n", j);
			putmatrix(B);
			break;
		case 6:
			goto beginning;
		default:
			goto whatoperation;
		}
		break;
	case 2: //矩阵消元
		if (choice2==0)
		{
whatelimination:
			Elimination();
			scanf("%d", &choice2);
		}
		switch (choice2)
		{
		case 0: //退出
			exit(0);
		case 1: //行阶梯型
			putmatrix(Gaussian(getmatrix(), 1));
			break;
		case 2: //最简行阶梯型
			putmatrix(Gaussian(getmatrix(), 2));
			break;
		case 3: //LU
			LU(getmatrix());
			break;
		case 4: //回主界面
			goto beginning;
		default:
			goto whatelimination;
		}
		break;
	case 3: //解方程组
		printf("\n对于系数矩阵:\n"
			"For the coefficient matrix:\n");
		A = getmatrix();
		printf("\n对于常数项:\n"
			"For the right-hand side of the system:\n");
		B = getvector();
		if (B[0][0]!=A[0][0])
		{
			printf("\n输入有误\n"
				"Incorrect input\n");
			break;
		}
		else if (A[0][0]==A[0][1])
		{
			if ( det(A) )
			{
				printf("\n该方程组有唯一解\n"
					"The system has a unique soluton\nx = ");
				putvector( mul( inverse(A) , B ) );
				break;
			}
			else
			{
				for (i=1, j=0; i<=B[0][0]; i++)
				{
					if (!B[i][1])
						j++;
				}
				if (j!=B[0][0])
				{
					printf("\n该方程组无解。\n"
						"The system has no solution.\n");
				}
				else
				{
					printf("\n该方程组有唯一解\n"
						"The system has a unique soluton\nx = ");
					putchar('(');
					for (i=1; i<=A[0][1]; i++)
					{
						printf("0, ");
					}
					printf("\b\b)\n");
				}
				break;
			}
		}
		else if (A[0][0]>A[0][1])
		{
			printf("\n你所输入的是一个超定方程组。\n"
				"What you have entered is an overdetermined system.\n"
				"该方程组的唯一最小二乘解为\n"
				"The unique least squares solution of the system is\n"
				"x = ");
			putvector( mul( mul( inverse( mul( transpose(A), A) ), transpose(A) ), B ) );
			break;
		}
		else if (A[0][0]<A[0][1])
		{
			printf("\n你所输入的是一个亚定方程组。\n"
				"What you have entered is an underdetermined system.\n"
				"该方程组的增广矩阵的最简行阶梯型为\n"
				"The reduced row echelon form of the augmented matrix for this system is\n");
			float **C;
			C = (float **)malloc( ((int)A[0][0]+1)*sizeof(float) );
			for (i=0; i<=A[0][0]; i++)
			{
				C[i] = (float *)malloc( ((int)(A[0][1]+B[0][1])+1)*sizeof(float) );
			}
			C[0][0] = A[0][0];
			C[0][1] = A[0][1]+B[0][1];
			for (i=1; i<=A[0][0]; i++)
			{
				for (j=1; j<=A[0][1]; j++)
				{
					C[i][j] = A[i][j];
				}
			}
			for (i=1; i<=B[0][0]; i++)
			{
				C[i][(int)A[0][1]+1] = B[i][1];
			}
			C = Gaussian(C, 3);
			for (i=1; i<=C[0][0]; i++)
			{
				for (j=1; j<=C[0][1]; j++)
				{
					if (C[i][j]>-1e-6 && C[i][j]<1e-6)
						C[i][j]=0;
				}
			}
			for (i=1; i<=A[0][0]; i++)
			{
				for (j=1; j<=A[0][1]; j++)
				{
					printf("%5g ", C[i][j] );
				}
				printf("| %5g\n", C[i][(int)C[0][1]]);
			}
			break;
		}
	case 4: //转置
		printf("\n对于矩阵A:\n"
			"For matrix A:\n");
		A = getmatrix();
		printf("\n该矩阵的转置矩阵为\n"
			"The transpose of this matrix is\n"
			"A^T = \n");
		putmatrix( transpose(A) );
		break;
	case 5: //行列式相关
		if (choice2==0)
		{
whatdeterminant:
			Determinant();
			scanf("%d", &choice2);
		}
		switch (choice2)
		{
		case 0: //退出
			exit(0);
		case 1: //行列式
			printf("\n对于矩阵A:\n"
				"For matrix A:\n");
			A = getmatrix();
			printf("\n该矩阵的行列式为\n"
				"The determinant of this matrix is\n"
				"|A| = %g\n", det(A));
			break;
		case 2: //余子矩阵
			printf("\n对于矩阵A:\n"
				"For matrix A:\n");
			A = getmatrix();
			printf("\n请分别输入aij项的下标i和j。\n"
				"Please enter the value of i and j for aij.\n");
			scanf("%d %d", &i, &j);
			if ( i<=A[0][0] && j<=A[0][1] )
			{
				printf("\na %d %d 的余子矩阵为\n", i, j);
				printf("The minor matrix of a %d %d is\n", i, j);
				putmatrix( minor(A, i, j) );
			}
			else
			{
				printf("\n输入有误\nIncorrect input\n");
			}
			break;
		case 3: //余子式
			printf("\n对于矩阵A:\n"
				"For matrix A:\n");
			A = getmatrix();
			printf("\n请分别输入aij项的下标i和j。\n"
				"Please enter the value of i and j for aij.\n");
			scanf("%d %d", &i, &j);
			if ( i<=A[0][0] && j<=A[0][1] )
			{
				printf("\na %d %d的余子式为%g.\n", i, j, det(minor(A, i, j)) );
				printf("The minor of a %d %d is %g.\n", i, j, det(minor(A, i, j)) );
			}
			else
			{
				printf("\n输入有误\nIncorrect input\n");
			}
			break;
		case 4: //代数余子式
			printf("\n对于矩阵A:\n"
				"For matrix A:\n");
			A = getmatrix();
			printf("\n请分别输入aij项的下标i和j。\n"
				"Please enter the value of i and j for aij.\n");
			scanf("%d %d", &i, &j);
			if ( i<=A[0][0] && j<=A[0][1] )
			{
				printf("\na %d %d的代数余子式为%g.\n", i, j, cofactor(A, i, j) );
				printf("The cofactor of a %d %d is %g.\n", i, j, cofactor(A, i, j) );
			}
			else
			{
				printf("\n输入有误\nIncorrect input\n");
			}
			break;
		case 5: //伴随矩阵
			printf("\n对于矩阵A:\n"
				"For matrix A:\n");
			A = getmatrix();
			printf("\n该矩阵的伴随矩阵为\n"
				"The adjoint of this matrix is\n"
				"adj A = \n");
			putmatrix( adj(A) );
			break;
		case 6: //回主界面
			goto beginning;
		default: //输入有误
			goto whatdeterminant;
		}
		break;
	case 6: //判断对称矩阵
		printf("\n对于矩阵:\n"
			"For matrix:\n");
		A = getmatrix();
		if(A[0][0]!=A[0][1])
		{
			printf("\n这 不是 对称矩阵。\n"
				"This is NOT a symmetric matrix.\n");
			break;
		}
		else
		{
			for(i=1;i<=A[0][0];i++)
			{
				for(j=i+1;j<=A[0][1];j++)
				{
					if(A[i][j]!=A[j][i])
					{
						printf("\n这 不是 对称矩阵。\n"
							"This is NOT a symmetric matrix.\n");
						break;
					}
				}
			}
		}
		printf("\n这 是 对称矩阵。\n"
			"This IS a symmetric matrix.\n");
		break;
	case 7: //坐标变换
		if (choice2==0)
		{
whatcoordinate:
			ChangeCoordinates();
			scanf("%d", &choice2);
		}
		switch (choice2)
		{
		case 0: //退出
			exit(0);
		case 1: //已有两组基
			printf("\n请输入向量空间的维度。Please enter the dimension of the vector space.\n");
			scanf("%d", &i);
			A = (float **)malloc( (i+1)*sizeof(float) );
			for (j=0; j<=i; j++)
			{
				A[j] = (float *)malloc( (i+1)*sizeof(float) );
			}
			A[0][0] = (float)i;
			A[0][1] = (float)i;
			printf("\n请输入原始基。Please enter the original basis.\n");
			for (i=1; i<=A[0][0]; i++)
			{
				printf("\n请输入第%d个向量。Please enter the %d vector.\n", i, i);
				for (j=1; j<=A[0][1]; j++)
				{
					scanf("%f", &A[j][i] );
				}
			}
			i = (int)A[0][0];
			B = (float **)malloc( (i+1)*sizeof(float) );
			for (j=0; j<=i; j++)
			{
				B[j] = (float *)malloc( (i+1)*sizeof(float) );
			}
			B[0][0] = (float)i;
			B[0][1] = (float)i;
			printf("\n请输入目标基。Please enter the target basis.\n");
			for (i=1; i<=B[0][0]; i++)
			{
				printf("\n请输入第%d个向量。Please enter the %d vector.\n", i, i);
				for (j=1; j<=B[0][1]; j++)
				{
					scanf("%f", &B[j][i] );
				}
			}
			A = mul(inverse(B), A);
			printf("\n对于原坐标向量:\n"
				"For the original coordinate vector:\n");
			B = getvector();
			printf("\n基变换后的坐标向量为:\n"
				"The coordinate vector after the change of basis is:\n");
			putvector( mul(A, B) );
			break;
		case 2: //已有过渡矩阵
			printf("\n请输入向量空间的维度。Please enter the dimension of the vector space.\n");
			scanf("%d", &i);
			A = (float **)malloc( (i+1)*sizeof(float) );
			for (j=0; j<=i; j++)
			{
				A[j] = (float *)malloc( (i+1)*sizeof(float) );
			}
			A[0][0] = (float)i;
			A[0][1] = (float)i;
			printf("\n请输入过渡矩阵。Please enter the transition matrix.\n");
			for (i=1; i<=A[0][0]; i++)
			{
				for (j=1; j<=A[0][1]; j++)
				{
					scanf("%f", &A[i][j] );
				}
			}
			printf("\n对于原坐标向量:\n"
				"For the original coordinate vector:\n");
			B = getvector();
			printf("\n基变换后的坐标向量为:\n"
				"The coordinate vector after the change of basis is:\n");
			putvector( mul(A, B) );
			break;
		case 3: //求过渡矩阵
			printf("\n请输入向量空间的维度。Please enter the dimension of the vector space.\n");
			scanf("%d", &i);
			A = (float **)malloc( (i+1)*sizeof(float) );
			for (j=0; j<=i; j++)
			{
				A[j] = (float *)malloc( (i+1)*sizeof(float) );
			}
			A[0][0] = (float)i;
			A[0][1] = (float)i;
			printf("\n请输入原始基。Please enter the original basis.\n");
			for (i=1; i<=A[0][0]; i++)
			{
				printf("\n请输入第%d个向量。Please enter the %d vector.\n", i, i);
				for (j=1; j<=A[0][1]; j++)
				{
					scanf("%f", &A[j][i] );
				}
			}
			i = (int)A[0][0];
			B = (float **)malloc( (i+1)*sizeof(float) );
			for (j=0; j<=i; j++)
			{
				B[j] = (float *)malloc( (i+1)*sizeof(float) );
			}
			B[0][0] = (float)i;
			B[0][1] = (float)i;
			printf("\n请输入目标基。Please enter the target basis.\n");
			for (i=1; i<=B[0][0]; i++)
			{
				printf("\n请输入第%d个向量。Please enter the %d vector.\n", i, i);
				for (j=1; j<=B[0][1]; j++)
				{
					scanf("%f", &B[j][i] );
				}
			}
			putmatrix( mul( inverse(B), A ) );
			break;
		case 4: //回主界面
			goto beginning;
		default: //输入有误
			goto whatcoordinate;
		}
		break;
	case 8: //欧几里得长度
		printf("\n对于向量x:\n"
			"For vector x:\n");
		A = getvector();
		printf("\n该向量的欧几里得长度为\n"
			"The Euclidean length of this vector is\n"
			"||x|| = %g\n", Euclen(A) );
		break;
	case 9: //向量间距
		printf("\n对于向量x:\n"
			"For vector x:\n");
		A = getvector();
		printf("\n对于向量y:\n"
			"For vector y:\n");
		B = getvector();
		if (A[0][0]==B[0][0])
		{
			printf("\n这两个向量之间的距离为\n"
				"The distance between these two vectors is\n"
				"||x-y|| = %g\n", Euclen(sub(A, B)) );
		}
		else
			printf("\n输入有误\nIncorrect input\n");
		break;
	case 10: //单位向量
		printf("\n对于向量:\n"
			"For vector:\n");
		A = getvector();
		if (Euclen(A))
		{
			printf("\n该向量的单位向量为\n"
				"The unit vector of this vector is\n");
			putvector( scmul( 1/Euclen(A) , A) );
		}
		else
			printf("\n这是一个零向量。\nThis is a null vector.\n");
		break;
	case 11: //投影
		printf("\n对于向量x:\n"
			"For vector x:\n");
		A = getvector();
		printf("\n对于向量y:\n"
			"For vector y:\n");
		B = getvector();
		if (A[0][0]==B[0][0] && Euclen(B))
		{
			printf("\nx在y上的标量投影为\n"
				"The scalar projection of x onto y is\n"
				"α = %g\n", inner(A, B)/Euclen(B) );
			printf("\nx在y上的向量投影为\n"
				"The vector projection of x onto y is\n"
				"p = " );
			putvector( scmul( inner(A, B)/inner(B, B) , B ) );
		}
		else
			printf("\n输入有误\nIncorrect input\n");
		break;
	case 12: //格拉姆-施密特
		if (choice2==0)
		{
whatGrSc:
			GrScInterface();
			scanf("%d", &choice2);
		}
		switch (choice2)
		{
		case 0: //退出
			exit(0);
		case 1: //正交基
			GramSchmidt(getmatrix(), 1);
			break;
		case 2: //QR
			GramSchmidt(getmatrix(), 2);
			break;
		case 3: //回主界面
			goto beginning;
		default: //输入有误
			goto whatGrSc;
		}
		break;
	case 13: //矩阵分解
		if (choice2==0)
		{
whatfactorization:
			MatrixFactorization();
			scanf("%d", &choice2);
		}
		switch (choice2)
		{
		case 0: //退出
			exit(0);
		case 1: //LU
			LU(getmatrix());
			break;
		case 2: //QR
			GramSchmidt(getmatrix(), 2);
			break;
		case 3: //回主界面
			goto beginning;
		default: //输入有误
			goto whatfactorization;
		}
		break;
	default: //输入有误
		goto beginning;
	}

	Sleep(3000);
whatNext:
	NextStepInterface();
	int Choice;
	scanf("%d", &Choice);
	switch (Choice)
	{
	case 0:
		exit(0);
	case 1:
		goto beginning;
	case 2:
		goto funtion;
	default:
		goto whatNext;
	}
}