#include<stdio.h>

int main()
{
	int a, b;
	int b1, b2, b3;

	scanf("%d%d", &a, &b);

	b1 = b / 100; b2 = b % 100 / 10; b3 = b % 10;

		printf("%d\n%d\n%d\n%d\n", a*b3,a*b2,a*b1,a*b);

}
