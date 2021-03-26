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
	case 0: //�˳�
		exit(0);
	case 1: //��������
		if (choice2==0)
		{
whatoperation:
			BasicOperation();
			scanf("%d", &choice2);
		}
		switch (choice2)
		{
		case 0: //�˳�
			exit(0);
		case 1: //��
			printf("\n���ڵ�һ������A:\n"
				"For the first matrix A:\n");
			A = getmatrix();
			printf("\n���ڵڶ�������B:\n"
				"For the second matrix B:\n");
			B = getmatrix();
			printf("\n����������ĺ�Ϊ\n"
				"The sum of these two matrices is\n"
				"A+B = \n");
			putmatrix( add(A, B) );
			break;
		case 2: //��
			printf("\n���ڵ�һ������A:\n"
				"For the first matrix A:\n");
			A = getmatrix();
			printf("\n���ڵڶ�������B:\n"
				"For the second matrix B:\n");
			B = getmatrix();
			printf("\n����������Ĳ�Ϊ\n"
				"The difference between these two matrices is\n"
				"A-B = \n");
			putmatrix( sub(A, B) );
			break;
		case 3: //��
			if (choice3==0)
			{
whatproduction:
				Production();
				scanf("%d", &choice3);
			}
			switch (choice3)
			{
			case 0: //�˳�
				exit(0);
			case 1: //������
				float scalar;
				printf("\n�������������ֵ��\n"
					"Please enter the value of the scalar ��: ");
				scanf("%f", &scalar);
				printf("\n���ھ���A:\n"
					"For the matrix A:\n");
				A = getmatrix();
				printf("\n�ñ��������Ļ�Ϊ\n"
					"The production of the scalar and the matrix is\n"
					"��A = \n");
				putmatrix( scmul(scalar, A) );
				break;
			case 2: //�����
				printf("\n���ڵ�һ������A:\n"
					"For the first matrix A:\n");
				A = getmatrix();
				printf("\n���ڵڶ�������B:\n"
					"For the second matrix B:\n");
				B = getmatrix();
				printf("\n����������Ļ�Ϊ\n"
					"The production of these two matrices is\n"
					"AB = \n");
				putmatrix( mul(A, B) );
				break;
			case 3: //�ڻ�
				printf("\n���ڵ�һ������x:\n"
					"For the first vector x:\n");
				A = getvector();
				printf("\n���ڵڶ�������B:\n"
					"For the second vector y:\n");
				B = getvector();
				printf("\n�������������ڻ�Ϊ\n"
					"The inner product of these two vectors is\n"
					"<x, y> = %g\n", inner(A, B) );
				break;
			case 4: //���
				printf("\n���ڵ�һ������x:\n"
					"For the first vector x:\n");
				A = getvector();
				printf("\n���ڵڶ�������B:\n"
					"For the second vector y:\n");
				B = getvector();
				printf("\n���������������Ϊ\n"
					"The outer product of these two vectors is\n"
					"x��y = ");
				putvector( outer(A, B) );
				break;
			case 5: //��������
				goto beginning;
			default: //��������
				goto whatproduction;
			}
			break;
		case 4: //��
			printf("\n���ھ���A:\n"
				"For matrix A:\n");
			A = getmatrix();
			if (!det(A))
			{
				printf("\n�������û�������\n"
					"This matrix has no inverse.\n");
			}
			else
			{
				printf("\n���������������\n"
					"The inverse of this matrix is\n"
					"A^(-1) = \n");
				putmatrix( inverse(A) );
			}
			break;
		case 5: //��
			printf("\n���ھ���A:\n"
				"For matrix A:\n");
			A = getmatrix();
			B = A;
			printf("\n������ָ����Please enter the exponent.\n");
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
	case 2: //������Ԫ
		if (choice2==0)
		{
whatelimination:
			Elimination();
			scanf("%d", &choice2);
		}
		switch (choice2)
		{
		case 0: //�˳�
			exit(0);
		case 1: //�н�����
			putmatrix(Gaussian(getmatrix(), 1));
			break;
		case 2: //����н�����
			putmatrix(Gaussian(getmatrix(), 2));
			break;
		case 3: //LU
			LU(getmatrix());
			break;
		case 4: //��������
			goto beginning;
		default:
			goto whatelimination;
		}
		break;
	case 3: //�ⷽ����
		printf("\n����ϵ������:\n"
			"For the coefficient matrix:\n");
		A = getmatrix();
		printf("\n���ڳ�����:\n"
			"For the right-hand side of the system:\n");
		B = getvector();
		if (B[0][0]!=A[0][0])
		{
			printf("\n��������\n"
				"Incorrect input\n");
			break;
		}
		else if (A[0][0]==A[0][1])
		{
			if ( det(A) )
			{
				printf("\n�÷�������Ψһ��\n"
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
					printf("\n�÷������޽⡣\n"
						"The system has no solution.\n");
				}
				else
				{
					printf("\n�÷�������Ψһ��\n"
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
			printf("\n�����������һ�����������顣\n"
				"What you have entered is an overdetermined system.\n"
				"�÷������Ψһ��С���˽�Ϊ\n"
				"The unique least squares solution of the system is\n"
				"x = ");
			putvector( mul( mul( inverse( mul( transpose(A), A) ), transpose(A) ), B ) );
			break;
		}
		else if (A[0][0]<A[0][1])
		{
			printf("\n�����������һ���Ƕ������顣\n"
				"What you have entered is an underdetermined system.\n"
				"�÷������������������н�����Ϊ\n"
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
	case 4: //ת��
		printf("\n���ھ���A:\n"
			"For matrix A:\n");
		A = getmatrix();
		printf("\n�þ����ת�þ���Ϊ\n"
			"The transpose of this matrix is\n"
			"A^T = \n");
		putmatrix( transpose(A) );
		break;
	case 5: //����ʽ���
		if (choice2==0)
		{
whatdeterminant:
			Determinant();
			scanf("%d", &choice2);
		}
		switch (choice2)
		{
		case 0: //�˳�
			exit(0);
		case 1: //����ʽ
			printf("\n���ھ���A:\n"
				"For matrix A:\n");
			A = getmatrix();
			printf("\n�þ��������ʽΪ\n"
				"The determinant of this matrix is\n"
				"|A| = %g\n", det(A));
			break;
		case 2: //���Ӿ���
			printf("\n���ھ���A:\n"
				"For matrix A:\n");
			A = getmatrix();
			printf("\n��ֱ�����aij����±�i��j��\n"
				"Please enter the value of i and j for aij.\n");
			scanf("%d %d", &i, &j);
			if ( i<=A[0][0] && j<=A[0][1] )
			{
				printf("\na %d %d �����Ӿ���Ϊ\n", i, j);
				printf("The minor matrix of a %d %d is\n", i, j);
				putmatrix( minor(A, i, j) );
			}
			else
			{
				printf("\n��������\nIncorrect input\n");
			}
			break;
		case 3: //����ʽ
			printf("\n���ھ���A:\n"
				"For matrix A:\n");
			A = getmatrix();
			printf("\n��ֱ�����aij����±�i��j��\n"
				"Please enter the value of i and j for aij.\n");
			scanf("%d %d", &i, &j);
			if ( i<=A[0][0] && j<=A[0][1] )
			{
				printf("\na %d %d������ʽΪ%g.\n", i, j, det(minor(A, i, j)) );
				printf("The minor of a %d %d is %g.\n", i, j, det(minor(A, i, j)) );
			}
			else
			{
				printf("\n��������\nIncorrect input\n");
			}
			break;
		case 4: //��������ʽ
			printf("\n���ھ���A:\n"
				"For matrix A:\n");
			A = getmatrix();
			printf("\n��ֱ�����aij����±�i��j��\n"
				"Please enter the value of i and j for aij.\n");
			scanf("%d %d", &i, &j);
			if ( i<=A[0][0] && j<=A[0][1] )
			{
				printf("\na %d %d�Ĵ�������ʽΪ%g.\n", i, j, cofactor(A, i, j) );
				printf("The cofactor of a %d %d is %g.\n", i, j, cofactor(A, i, j) );
			}
			else
			{
				printf("\n��������\nIncorrect input\n");
			}
			break;
		case 5: //�������
			printf("\n���ھ���A:\n"
				"For matrix A:\n");
			A = getmatrix();
			printf("\n�þ���İ������Ϊ\n"
				"The adjoint of this matrix is\n"
				"adj A = \n");
			putmatrix( adj(A) );
			break;
		case 6: //��������
			goto beginning;
		default: //��������
			goto whatdeterminant;
		}
		break;
	case 6: //�ж϶Գƾ���
		printf("\n���ھ���:\n"
			"For matrix:\n");
		A = getmatrix();
		if(A[0][0]!=A[0][1])
		{
			printf("\n�� ���� �Գƾ���\n"
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
						printf("\n�� ���� �Գƾ���\n"
							"This is NOT a symmetric matrix.\n");
						break;
					}
				}
			}
		}
		printf("\n�� �� �Գƾ���\n"
			"This IS a symmetric matrix.\n");
		break;
	case 7: //����任
		if (choice2==0)
		{
whatcoordinate:
			ChangeCoordinates();
			scanf("%d", &choice2);
		}
		switch (choice2)
		{
		case 0: //�˳�
			exit(0);
		case 1: //���������
			printf("\n�����������ռ��ά�ȡ�Please enter the dimension of the vector space.\n");
			scanf("%d", &i);
			A = (float **)malloc( (i+1)*sizeof(float) );
			for (j=0; j<=i; j++)
			{
				A[j] = (float *)malloc( (i+1)*sizeof(float) );
			}
			A[0][0] = (float)i;
			A[0][1] = (float)i;
			printf("\n������ԭʼ����Please enter the original basis.\n");
			for (i=1; i<=A[0][0]; i++)
			{
				printf("\n�������%d��������Please enter the %d vector.\n", i, i);
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
			printf("\n������Ŀ�����Please enter the target basis.\n");
			for (i=1; i<=B[0][0]; i++)
			{
				printf("\n�������%d��������Please enter the %d vector.\n", i, i);
				for (j=1; j<=B[0][1]; j++)
				{
					scanf("%f", &B[j][i] );
				}
			}
			A = mul(inverse(B), A);
			printf("\n����ԭ��������:\n"
				"For the original coordinate vector:\n");
			B = getvector();
			printf("\n���任�����������Ϊ:\n"
				"The coordinate vector after the change of basis is:\n");
			putvector( mul(A, B) );
			break;
		case 2: //���й��ɾ���
			printf("\n�����������ռ��ά�ȡ�Please enter the dimension of the vector space.\n");
			scanf("%d", &i);
			A = (float **)malloc( (i+1)*sizeof(float) );
			for (j=0; j<=i; j++)
			{
				A[j] = (float *)malloc( (i+1)*sizeof(float) );
			}
			A[0][0] = (float)i;
			A[0][1] = (float)i;
			printf("\n��������ɾ���Please enter the transition matrix.\n");
			for (i=1; i<=A[0][0]; i++)
			{
				for (j=1; j<=A[0][1]; j++)
				{
					scanf("%f", &A[i][j] );
				}
			}
			printf("\n����ԭ��������:\n"
				"For the original coordinate vector:\n");
			B = getvector();
			printf("\n���任�����������Ϊ:\n"
				"The coordinate vector after the change of basis is:\n");
			putvector( mul(A, B) );
			break;
		case 3: //����ɾ���
			printf("\n�����������ռ��ά�ȡ�Please enter the dimension of the vector space.\n");
			scanf("%d", &i);
			A = (float **)malloc( (i+1)*sizeof(float) );
			for (j=0; j<=i; j++)
			{
				A[j] = (float *)malloc( (i+1)*sizeof(float) );
			}
			A[0][0] = (float)i;
			A[0][1] = (float)i;
			printf("\n������ԭʼ����Please enter the original basis.\n");
			for (i=1; i<=A[0][0]; i++)
			{
				printf("\n�������%d��������Please enter the %d vector.\n", i, i);
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
			printf("\n������Ŀ�����Please enter the target basis.\n");
			for (i=1; i<=B[0][0]; i++)
			{
				printf("\n�������%d��������Please enter the %d vector.\n", i, i);
				for (j=1; j<=B[0][1]; j++)
				{
					scanf("%f", &B[j][i] );
				}
			}
			putmatrix( mul( inverse(B), A ) );
			break;
		case 4: //��������
			goto beginning;
		default: //��������
			goto whatcoordinate;
		}
		break;
	case 8: //ŷ����ó���
		printf("\n��������x:\n"
			"For vector x:\n");
		A = getvector();
		printf("\n��������ŷ����ó���Ϊ\n"
			"The Euclidean length of this vector is\n"
			"||x|| = %g\n", Euclen(A) );
		break;
	case 9: //�������
		printf("\n��������x:\n"
			"For vector x:\n");
		A = getvector();
		printf("\n��������y:\n"
			"For vector y:\n");
		B = getvector();
		if (A[0][0]==B[0][0])
		{
			printf("\n����������֮��ľ���Ϊ\n"
				"The distance between these two vectors is\n"
				"||x-y|| = %g\n", Euclen(sub(A, B)) );
		}
		else
			printf("\n��������\nIncorrect input\n");
		break;
	case 10: //��λ����
		printf("\n��������:\n"
			"For vector:\n");
		A = getvector();
		if (Euclen(A))
		{
			printf("\n�������ĵ�λ����Ϊ\n"
				"The unit vector of this vector is\n");
			putvector( scmul( 1/Euclen(A) , A) );
		}
		else
			printf("\n����һ����������\nThis is a null vector.\n");
		break;
	case 11: //ͶӰ
		printf("\n��������x:\n"
			"For vector x:\n");
		A = getvector();
		printf("\n��������y:\n"
			"For vector y:\n");
		B = getvector();
		if (A[0][0]==B[0][0] && Euclen(B))
		{
			printf("\nx��y�ϵı���ͶӰΪ\n"
				"The scalar projection of x onto y is\n"
				"�� = %g\n", inner(A, B)/Euclen(B) );
			printf("\nx��y�ϵ�����ͶӰΪ\n"
				"The vector projection of x onto y is\n"
				"p = " );
			putvector( scmul( inner(A, B)/inner(B, B) , B ) );
		}
		else
			printf("\n��������\nIncorrect input\n");
		break;
	case 12: //����ķ-ʩ����
		if (choice2==0)
		{
whatGrSc:
			GrScInterface();
			scanf("%d", &choice2);
		}
		switch (choice2)
		{
		case 0: //�˳�
			exit(0);
		case 1: //������
			GramSchmidt(getmatrix(), 1);
			break;
		case 2: //QR
			GramSchmidt(getmatrix(), 2);
			break;
		case 3: //��������
			goto beginning;
		default: //��������
			goto whatGrSc;
		}
		break;
	case 13: //����ֽ�
		if (choice2==0)
		{
whatfactorization:
			MatrixFactorization();
			scanf("%d", &choice2);
		}
		switch (choice2)
		{
		case 0: //�˳�
			exit(0);
		case 1: //LU
			LU(getmatrix());
			break;
		case 2: //QR
			GramSchmidt(getmatrix(), 2);
			break;
		case 3: //��������
			goto beginning;
		default: //��������
			goto whatfactorization;
		}
		break;
	default: //��������
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