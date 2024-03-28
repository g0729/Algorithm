#include<stdio.h>
#include<math.h>
main()
{
	int a, b, c;
	double dev;
	scanf("%d%d%d", &a, &b, &c);
	dev = (double)a / (c - b);
	
	if (b >= c)
		printf("-1");
	else if (dev - floor(dev) == 0)
		printf("%0.lf", dev + 1);
	else
		printf("%0.lf", ceil(dev));
}