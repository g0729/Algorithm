#include<stdio.h>
main()
{
	int a;
	scanf("%d", &a);
	
	for (int i = 0; i < a; i++)
	{
		for (int p = 1; p < a-i; p++)
			printf(" ");
		for (int q = 0; q <= i; q++)
			printf("*");
		printf("\n");
	}
}