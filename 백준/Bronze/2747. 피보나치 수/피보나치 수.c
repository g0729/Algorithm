#include<stdio.h>
main()
{
	int arr[46];
	arr[0] = 0;
	arr[1] = 1;
	for (int i = 2; i < 46; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	int n;
	scanf("%d", &n);

	printf("%d", arr[n]);
	
}