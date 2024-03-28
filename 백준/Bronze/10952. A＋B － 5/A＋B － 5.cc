#include<stdio.h>
main()
{
	int A, B;
	A = B = 1;

	while(1)
	{
		scanf("%d%d", &A, &B);
		if (A == 0 && B == 0)
			break;
		printf("%d\n",A+B);
	}
}