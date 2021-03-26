#ifndef VECTORIO
#define VECTORIO

#include <stdio.h>
#include <stdlib.h>

float **getvector()
{
	float **vector;

	int m, i;

	printf("请输入向量的维度。\n"
		"Please enter the dimension of the vector.\n");
	scanf("%d", &m);

	vector = (float **)malloc( (m+1)*sizeof(float) );

	for (i=0; i<=m; i++)
	{
		vector[i] = (float *)malloc(2*sizeof(float));
	}

	vector[0][0] = (float)m;
	vector[0][1] = 1;

	printf("请输入内容。\n"
		"Please enter the entries.\n");
	for (i=1; i<=m; i++)
	{
		scanf("%f", &vector[i][1]);
	}

	return (vector);
}

void putvector(float **vector)
{
	if (vector!=NULL)
	{
		int m, i;

		m = (int)vector[0][0];

		putchar('(');
		for (i=1; i<=m; i++)
		{
			printf("%g, ", vector[i][1]);
		}
		printf("\b\b)\n");
	}
	else
		;
}

#endif