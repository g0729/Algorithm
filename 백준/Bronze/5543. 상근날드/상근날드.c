#include<stdio.h>
main()
{
	int min = 2000;
	int sum = 0;
	int n;

	for (int i = 0; i < 3; i++)
	{
		scanf("%d", &n);
		if (n < min)
			min = n;
	}
	sum += min;
	min = 2000;
	for (int i = 0; i < 2; i++)
	{
		scanf("%d", &n);
		if (n < min)
		min = n;
	}
	printf("%d", sum + min - 50);

}