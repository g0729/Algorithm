#include<stdio.h>
#include<stdlib.h>
main()
{
	char a[4], b[4];
	char n;

	scanf("%s%s", a,b);
	n = a[0];
	a[0] = a[2];
	a[2] = n;
	n = b[0];
	b[0] = b[2];
	b[2] = n;
	if (atoi(a) > atoi(b))
		printf("%s", a);
	else
		printf("%s", b);
	
}