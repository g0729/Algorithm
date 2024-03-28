#include<stdio.h>
main()
{
	int n;
	scanf("%d", &n);
	int arr[50][2];
	for (int i = 0; i < n; i++)
	{
		for(int j = 0;j<2;j++)
		scanf("%d", &arr[i][j]);
	}
	for (int i = 0; i < n; i++)
	{
		int count = 1;
		for (int j = 0; j < n; j++)
		{
			if (arr[i][0] < arr[j][0] && arr[i][1] < arr[j][1])
				count++;
		}
		printf("%d ", count);
	}

}