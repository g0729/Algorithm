#include<stdio.h>
main()
{
	int arr[1000];
	int n,a,same;
	scanf("%d", &n);
	same = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n -1- i;j++)
		{
			if (arr[j] > arr[j + 1])
			{
				a= arr[j+1];
				arr[j+1]=arr[j];
				arr[j] = a;
			}
		}
	}
	printf("%d\n", arr[0]);
	for (int i = 1; i < n; i++)
	{
		if (arr[i - 1] != arr[i])
			printf("%d\n", arr[i]);
	}
}