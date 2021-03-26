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
	printf("┃                 欢迎使用线性代数计算器。                ┃\n");
	printf("┃    Welcome to use the calculator for linear algebra.    ┃\n");
	printf("┃                请输入数字以执行相应功能。               ┃\n");
	printf("┃  Please enter a number to opearte the related function. ┃\n");
	printf("┃                    暂不支持使用分数。                   ┃\n");
	printf("┃           Fractions are not supported so far.           ┃\n");
	printf("┃╭ ------------------------------------------------------╮┃\n");
	printf("┃┃ 1.基础运算        Basic operations                    ┃┃\n");
	printf("┃┃ 2.矩阵消元        Matrix elimination                  ┃┃\n");
	printf("┃┃ 3.解线性方程组    Solve a system of linear equations  ┃┃\n");
	printf("┃┃ 4.求转置矩阵      Find the transpose of a matrix      ┃┃\n");
	printf("┃┃ 5.行列式相关      Determinant-related                 ┃┃\n");
	printf("┃┃ 6.判断矩阵对称性  Determine the symmetry of matrices  ┃┃\n");
	printf("┃┃ 7.坐标变换        Changing coordinates                ┃┃\n");
	printf("┃┃ 8.求欧几里得长度  Compute Euclidean length            ┃┃\n");
	printf("┃┃ 9.求向量的间距    Compute the distance between vectors┃┃\n");
	printf("┃┃ 10.求单位向量     Find the unit vector of a vector    ┃┃\n");
	printf("┃┃ 11.求投影         Find projection                     ┃┃\n");
	printf("┃┃ 12.格拉姆-施密特  The Gram-Schmidt                    ┃┃\n");
	printf("┃┃    正交化过程     Orthogonalization Process           ┃┃\n");
	printf("┃┃ 13.矩阵分解       Matrix factorization                ┃┃\n");
	printf("┃┃ 0.退出            Exit this programme                 ┃┃\n");
	printf("┃╰ ------------------------------------------------------╯┃\n");
	printf(" \\________________________________________________________/\n");
	printf("制作者 Programmers\n");
	printf("郝宇焜 HAO Yukun  代泽轶 DAI Zeyi  田瀚 TIAN Han\n");
	printf("请输入你的选择。Please enter your choice.\n");
	printf(">>>");
}

void NextStepInterface(void)
{
	printf("  ______________________________________________________ \n");
	printf(" /                                                      \\\n");
	printf("┃                 请问你下一步想做什么？                ┃\n");
	printf("┃              What do you want to do next?             ┃\n");
	printf("┃                                                       ┃\n");
	printf("┃                请输入数字以执行相应功能。             ┃\n");
	printf("┃ Please enter a number to opearte the related function.┃\n");
	printf("┃                                                       ┃\n");
	printf("┃╭ ----------------------------------------------------╮┃\n");
	printf("┃┃ 1.回到主界面       Back to the main interface       ┃┃\n");
	printf("┃┃ 2.再次执行当前功能 Execute current function again   ┃┃\n");
	printf("┃┃ 0.退出             Exit this programme              ┃┃\n");
	printf("┃╰ ----------------------------------------------------╯┃\n");
	printf(" \\______________________________________________________/\n");
	printf(">>>");
}

void BasicOperation(void)
{
	printf("╭ ----------------------------------------------------╮\n");
	printf("┃ 1.求和          Find sum of two matrices            ┃\n");
	printf("┃ 2.求差          Find difference between two matrices┃\n");
	printf("┃ 3.求积          Find production                     ┃\n");
	printf("┃ 4.求逆          Find the inverse of a matrix        ┃\n");
	printf("┃ 5.求幂          Find the power of a matrix          ┃\n");
	printf("┃ 6.回主界面      Back to the main interface          ┃\n");
	printf("┃ 0.退出          Exit this programme                 ┃\n");
	printf("╰ ----------------------------------------------------╯\n");
	printf(">>>");
}

void Production(void)
{
	printf("╭ ----------------------------------------------------╮\n");
	printf("┃ 1.标量乘法      Scalar Multiplication               ┃\n");
	printf("┃ 2.矩阵乘法      Matrix Multiplication               ┃\n");
	printf("┃ 3.内积/点积/标量积                                  ┃\n");
	printf("┃   Inner/dot/scalar product on a vector space        ┃\n");
	printf("┃ 4.外积/叉积/向量积                                  ┃\n");
	printf("┃   Outer/cross/vector product on a vector space      ┃\n");
	printf("┃ 5.回主界面      Back to the main interface          ┃\n");
	printf("┃ 0.退出          Exit this programme                 ┃\n");
	printf("╰ ----------------------------------------------------╯\n");
	printf(">>>");
}

void Determinant(void)
{
	printf("╭ ----------------------------------------------------╮\n");
	printf("┃ 1.求行列式      Find the determinant of a matrix    ┃\n");
	printf("┃ 2.求余子矩阵    Find a minor matirx                 ┃\n");
	printf("┃ 3.求余子式      Find a minor                        ┃\n");
	printf("┃ 4.求代数余子式  Find a cafactor                     ┃\n");
	printf("┃ 5.求伴随矩阵    Find the adjoint of a matrix        ┃\n");
	printf("┃ 6.回主界面      Back to the main interface          ┃\n");
	printf("┃ 0.退出          Exit this programme                 ┃\n");
	printf("╰ ----------------------------------------------------╯\n");
	printf(">>>");
}

void ChangeCoordinates(void)
{
	printf("╭ ----------------------------------------------------╮\n");
	printf("┃ 1.已有两组基    Already have two basis              ┃\n");
	printf("┃ 2.已有过渡矩阵  Already have a transition matrix    ┃\n");
	printf("┃ 3.求过渡矩阵    Find the transition matrix          ┃\n");
	printf("┃ 4.回主界面      Back to the main interface          ┃\n");
	printf("┃ 0.退出          Exit this programme                 ┃\n");
	printf("╰ ----------------------------------------------------╯\n");
	printf(">>>");
}

void Elimination(void)
{
	printf("╭ ----------------------------------------------------╮\n");
	printf("┃ 1.高斯消元法       Gaussian elimination             ┃\n");
	printf("┃   ->行阶梯型       ->row echelon form               ┃\n");
	printf("┃ 2.高斯-若尔当化简  Gauss-Jordan reduction           ┃\n");
	printf("┃   ->最简行阶梯型   ->reduced row echelon form       ┃\n");
	printf("┃ 3.LU分解           LU Factorization                 ┃\n");
	printf("┃ 4.回主界面         Back to the main interface       ┃\n");
	printf("┃ 0.退出             Exit this programme              ┃\n");
	printf("╰ ----------------------------------------------------╯\n");
	printf(">>>");
}

void GrScInterface(void)
{
	printf("╭ ----------------------------------------------------╮\n");
	printf("┃ 1.求标准正交基  Find orthonormal basis              ┃\n");
	printf("┃ 2.QR分解        QR Factorization                    ┃\n");
	printf("┃ 3.回主界面      Back to the main interface          ┃\n");
	printf("┃ 0.退出          Exit this programme                 ┃\n");
	printf("╰ ----------------------------------------------------╯\n");
	printf(">>>");
}

void MatrixFactorization(void)
{
	printf("╭ ----------------------------------------------------╮\n");
	printf("┃ 1.LU/三角分解   LU/Triangular Factorization         ┃\n");
	printf("┃ 2.QR分解        QR Factorization                    ┃\n");
	printf("┃ 3.回主界面      Back to the main interface          ┃\n");
	printf("┃ 0.退出          Exit this programme                 ┃\n");
	printf("╰ ----------------------------------------------------╯\n");
	printf(">>>");
}