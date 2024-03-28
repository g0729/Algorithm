#include<stdio.h>

int main()
{
	int a,b;
	b = 0;
	scanf("%d", &a);

	if (a % 400 == 0||(a%4==0&&a%100!=0))
		b = 1;
	
	printf("%d", b);
}
