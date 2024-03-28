#include<stdio.h>
int a(int n)
{
	if (n == 1)
		return 0;
	if (n == 2)
		return 1;
	return a(n - 1) + a(n - 2);
}
main()
{
	int n;
	scanf("%d", &n);
	printf("%d", a(n+1));
}