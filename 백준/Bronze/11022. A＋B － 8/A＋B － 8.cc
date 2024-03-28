#include<stdio.h>
main()
{
	int a;
	scanf("%d", &a);
	for (int i = 1; i <= a; i++)
	{
		int A, B;
		scanf("%d%d", &A, &B);
		printf("Case #%d: %d + %d = %d\n",i,A,B, A + B);
	}
}