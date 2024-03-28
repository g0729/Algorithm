#include<stdio.h>
shorter(int a, int b)
{
	return b - a > a ? a : b - a;
}
main()
{
	int x, y, w, h;

	scanf("%d%d%d%d", &x, &y, &w, &h);

	printf("%d", shorter(x, w) > shorter(y, h) ? shorter(y, h) : shorter(x, w));
}
