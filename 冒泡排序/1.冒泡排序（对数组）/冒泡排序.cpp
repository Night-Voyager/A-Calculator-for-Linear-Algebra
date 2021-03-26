#include <stdio.h>

void bubble_sort(float a[], int n);

void main()
{
	float a[] = {3.14, 1.414, 9.8};
	int x=sizeof(a)/sizeof(float);
	printf("%d\n", x);
	bubble_sort(a, x);
	for (int i=0; i<=x-1; i++)
		printf("%g ", a[i]);
}

void bubble_sort(float a[], int n)
{
    int i, j;
	float temp;
    for (j = 0; j < n - 1; j++)
	{
        for (i = 0; i < n - 1 - j; i++)
        {
            if(a[i] > a[i + 1])
            {
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
	}
}