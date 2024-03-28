#include<stdio.h>
main()
{
	int n;
	int min, max,a;
	max = 0,min=1;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		if (a > max)
			max = a;
		if (min == 1)
		{
			min = a;
			continue;
		}
		if (a < min)
			min = a;
	}

	printf("%d", min * max);

	
}