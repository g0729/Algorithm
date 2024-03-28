#include<stdio.h>
main()
{
	int x[3];
	int y[3];
	int resX, resY;
	
	for (int i = 0; i < 3; i++)
	{
		scanf("%d%d", &x[i], &y[i]);
	}
	if (x[0] != x[1])
	{
		if (x[1] == x[2])
			resX = x[0];
		else
			resX = x[1];
	}
	else
		resX = x[2];
	if (y[0] != y[1])
	{
		if (y[1] == y[2])
			resY = y[0];
		else
			resY = y[1];
	}
	else
		resY = y[2];
	printf("%d %d", resX, resY);
}