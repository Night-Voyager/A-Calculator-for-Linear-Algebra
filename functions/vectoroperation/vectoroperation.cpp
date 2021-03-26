#ifndef VECTOROPERATION
#define VECTOROPERATION

#ifndef MAIN_FUNTION
#define MAIN_FUNTION
#define VECTOROPERATION_OK
#endif

#include <math.h>
#include "..\vectorio\vectorio.h"
#include "..\arithmetic\arithmetic.cpp"
#include "..\transpose\transpose.cpp"

float Euclen(float **);
float inner(float **, float **);
float **outer(float **, float **);

#ifdef VECTOROPERATION_OK
void main()
{
	float **x, **y;
	x = getvector();
	y = getvector();
	printf("%g %g\n%g\n", Euclen(x), Euclen(y), inner(x, y));
	putvector(outer(x, y));
}
#endif

float Euclen(float **vector)
{
	float **x;
	x = mul( transpose(vector), vector);
	return ((float)sqrt(x[1][1]));
}

float inner(float **a, float **b)
{
	float sum;
	if (a[0][0]!=b[0][0])
	{
		printf("\n输入有误\nIncorrect input\n");
	}
	else
	{
		sum = 0;
		for(int i = 1; i<=a[0][0]; i++)
		{
			sum+=a[i][1]*b[i][1];
		}
	}
	return (sum);
}

float **outer(float **a, float **b)
{
	if ( a[0][0]!=3 || b[0][0]!=3 )
	{
		printf("\n输入有误\nIncorrect input\n");
		return (NULL);
	}
	else
	{
		float **vector;

		vector = (float **)malloc(4*sizeof(float));

		for (int i=0; i<=4; i++)
		{
			vector[i] = (float *)malloc(2*sizeof(float));
		}

		vector[0][0] = 3;
		vector[0][1] = 1;

		vector[1][1] = a[2][1]*b[3][1] - b[2][1]*a[3][1];
		vector[2][1] = b[1][1]*a[3][1] - a[1][1]*b[3][1];
		vector[3][1] = a[1][1]*b[2][1] - b[1][1]*a[2][1];

		return (vector);
	}
}

#endif