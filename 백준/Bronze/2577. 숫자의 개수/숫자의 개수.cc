#include<stdio.h>
main()
{
	int N = 1;
	int a, b;
	int arr[10] = { 0 };
	
	for (int q = 0; q < 3; q++)
	{
		scanf("%d", &a);
		N = N * a;
	}
	while (N != 0)
	{
		b = N % 10;
		arr[b] = arr[b] + 1;
		N /= 10;
		
	}
	for (int q = 0; q < 10; q++)
		printf("%d\n",arr[q]);
}