#include<stdio.h>
main() {
	int a, n, i = 0;
	int distance;
	a = 2;
	scanf("%d", &n);
	if (n == 1)
	{
			printf("1");
	return 0;
}

	while (a<= n)
	{
		a += 6 * i;
		i++;
	}
	
		printf("%d", i);
}