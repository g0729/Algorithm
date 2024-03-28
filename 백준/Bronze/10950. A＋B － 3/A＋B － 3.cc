#include<stdio.h>
main()
{
	int a;
	scanf("%d", &a);
	for (int i = 0; i < a; i++)
	{
		int A, B;
		scanf("%d%d", &A, &B);
		printf("%d\n", A + B);
	}
}