#include<stdio.h>
main()
{
	int x, n, i;
	n = 0;
	i = 1;
	scanf("%d", &x);
	if (x == 1)
	{
		printf("1/1");
		return 0;
	}
	while (x>n)
	{
		n += i;
		i++;
	}
	n = n - i+1;
	if (i % 2 == 1)
	{
		printf("%d/%d", x - n, i - x + n);
	}
	else
		printf("%d/%d", i - x + n, x - n);
}