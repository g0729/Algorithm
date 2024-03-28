#include "stdio.h"
int main()
{
	int arr[42] = { 0 };
	int b,n;
	n = 0;
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &b);
		arr[b % 42]++;
	}
	for (int i = 0; i < 42; i++)
		if (arr[i] > 0)
			n++;
	printf("%d", n);
}