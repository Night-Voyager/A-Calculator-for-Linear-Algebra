#include <stdio.h>

void WelcomingInterface(void);
void NextStepInterface(void);
void BasicOpreation(void);
void Production(void);
void Determinant(void);
void ChangeCoordinates(void);
void Elimination(void);
void GrScInterface(void);
void MatrixFactorization(void);

#ifndef MAIN_FUNTION
void main()
{
	WelcomingInterface();

	int choice = 0;
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		printf("1\n");
		break;
	case 2:
		printf("2\n");
		break;
	}
}
#endif

void WelcomingInterface(void)
{
	printf("  ________________________________________________________ \n");
	printf(" /                                                        \\\n");
	printf("��                 ��ӭʹ�����Դ�����������                ��\n");
	printf("��    Welcome to use the calculator for linear algebra.    ��\n");
	printf("��                ������������ִ����Ӧ���ܡ�               ��\n");
	printf("��  Please enter a number to opearte the related function. ��\n");
	printf("��                    �ݲ�֧��ʹ�÷�����                   ��\n");
	printf("��           Fractions are not supported so far.           ��\n");
	printf("���q ------------------------------------------------------�r��\n");
	printf("���� 1.��������        Basic operations                    ����\n");
	printf("���� 2.������Ԫ        Matrix elimination                  ����\n");
	printf("���� 3.�����Է�����    Solve a system of linear equations  ����\n");
	printf("���� 4.��ת�þ���      Find the transpose of a matrix      ����\n");
	printf("���� 5.����ʽ���      Determinant-related                 ����\n");
	printf("���� 6.�жϾ���Գ���  Determine the symmetry of matrices  ����\n");
	printf("���� 7.����任        Changing coordinates                ����\n");
	printf("���� 8.��ŷ����ó���  Compute Euclidean length            ����\n");
	printf("���� 9.�������ļ��    Compute the distance between vectors����\n");
	printf("���� 10.��λ����     Find the unit vector of a vector    ����\n");
	printf("���� 11.��ͶӰ         Find projection                     ����\n");
	printf("���� 12.����ķ-ʩ����  The Gram-Schmidt                    ����\n");
	printf("����    ����������     Orthogonalization Process           ����\n");
	printf("���� 13.����ֽ�       Matrix factorization                ����\n");
	printf("���� 0.�˳�            Exit this programme                 ����\n");
	printf("���t ------------------------------------------------------�s��\n");
	printf(" \\________________________________________________________/\n");
	printf("������ Programmers\n");
	printf("����j HAO Yukun  ������ DAI Zeyi  ��� TIAN Han\n");
	printf("���������ѡ��Please enter your choice.\n");
	printf(">>>");
}

void NextStepInterface(void)
{
	printf("  ______________________________________________________ \n");
	printf(" /                                                      \\\n");
	printf("��                 ��������һ������ʲô��                ��\n");
	printf("��              What do you want to do next?             ��\n");
	printf("��                                                       ��\n");
	printf("��                ������������ִ����Ӧ���ܡ�             ��\n");
	printf("�� Please enter a number to opearte the related function.��\n");
	printf("��                                                       ��\n");
	printf("���q ----------------------------------------------------�r��\n");
	printf("���� 1.�ص�������       Back to the main interface       ����\n");
	printf("���� 2.�ٴ�ִ�е�ǰ���� Execute current function again   ����\n");
	printf("���� 0.�˳�             Exit this programme              ����\n");
	printf("���t ----------------------------------------------------�s��\n");
	printf(" \\______________________________________________________/\n");
	printf(">>>");
}

void BasicOperation(void)
{
	printf("�q ----------------------------------------------------�r\n");
	printf("�� 1.���          Find sum of two matrices            ��\n");
	printf("�� 2.���          Find difference between two matrices��\n");
	printf("�� 3.���          Find production                     ��\n");
	printf("�� 4.����          Find the inverse of a matrix        ��\n");
	printf("�� 5.����          Find the power of a matrix          ��\n");
	printf("�� 6.��������      Back to the main interface          ��\n");
	printf("�� 0.�˳�          Exit this programme                 ��\n");
	printf("�t ----------------------------------------------------�s\n");
	printf(">>>");
}

void Production(void)
{
	printf("�q ----------------------------------------------------�r\n");
	printf("�� 1.�����˷�      Scalar Multiplication               ��\n");
	printf("�� 2.����˷�      Matrix Multiplication               ��\n");
	printf("�� 3.�ڻ�/���/������                                  ��\n");
	printf("��   Inner/dot/scalar product on a vector space        ��\n");
	printf("�� 4.���/���/������                                  ��\n");
	printf("��   Outer/cross/vector product on a vector space      ��\n");
	printf("�� 5.��������      Back to the main interface          ��\n");
	printf("�� 0.�˳�          Exit this programme                 ��\n");
	printf("�t ----------------------------------------------------�s\n");
	printf(">>>");
}

void Determinant(void)
{
	printf("�q ----------------------------------------------------�r\n");
	printf("�� 1.������ʽ      Find the determinant of a matrix    ��\n");
	printf("�� 2.�����Ӿ���    Find a minor matirx                 ��\n");
	printf("�� 3.������ʽ      Find a minor                        ��\n");
	printf("�� 4.���������ʽ  Find a cafactor                     ��\n");
	printf("�� 5.��������    Find the adjoint of a matrix        ��\n");
	printf("�� 6.��������      Back to the main interface          ��\n");
	printf("�� 0.�˳�          Exit this programme                 ��\n");
	printf("�t ----------------------------------------------------�s\n");
	printf(">>>");
}

void ChangeCoordinates(void)
{
	printf("�q ----------------------------------------------------�r\n");
	printf("�� 1.���������    Already have two basis              ��\n");
	printf("�� 2.���й��ɾ���  Already have a transition matrix    ��\n");
	printf("�� 3.����ɾ���    Find the transition matrix          ��\n");
	printf("�� 4.��������      Back to the main interface          ��\n");
	printf("�� 0.�˳�          Exit this programme                 ��\n");
	printf("�t ----------------------------------------------------�s\n");
	printf(">>>");
}

void Elimination(void)
{
	printf("�q ----------------------------------------------------�r\n");
	printf("�� 1.��˹��Ԫ��       Gaussian elimination             ��\n");
	printf("��   ->�н�����       ->row echelon form               ��\n");
	printf("�� 2.��˹-����������  Gauss-Jordan reduction           ��\n");
	printf("��   ->����н�����   ->reduced row echelon form       ��\n");
	printf("�� 3.LU�ֽ�           LU Factorization                 ��\n");
	printf("�� 4.��������         Back to the main interface       ��\n");
	printf("�� 0.�˳�             Exit this programme              ��\n");
	printf("�t ----------------------------------------------------�s\n");
	printf(">>>");
}

void GrScInterface(void)
{
	printf("�q ----------------------------------------------------�r\n");
	printf("�� 1.���׼������  Find orthonormal basis              ��\n");
	printf("�� 2.QR�ֽ�        QR Factorization                    ��\n");
	printf("�� 3.��������      Back to the main interface          ��\n");
	printf("�� 0.�˳�          Exit this programme                 ��\n");
	printf("�t ----------------------------------------------------�s\n");
	printf(">>>");
}

void MatrixFactorization(void)
{
	printf("�q ----------------------------------------------------�r\n");
	printf("�� 1.LU/���Ƿֽ�   LU/Triangular Factorization         ��\n");
	printf("�� 2.QR�ֽ�        QR Factorization                    ��\n");
	printf("�� 3.��������      Back to the main interface          ��\n");
	printf("�� 0.�˳�          Exit this programme                 ��\n");
	printf("�t ----------------------------------------------------�s\n");
	printf(">>>");
}