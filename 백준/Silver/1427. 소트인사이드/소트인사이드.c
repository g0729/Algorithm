#include<stdio.h>
main()
{
	int n,i,temp;
	scanf("%d", &n);
	short arr[10];
	for (i = 0; n > 0; n = n / 10, i++)
		arr[i] = n%10;
	for (int q = i-1; q > 0; q--)
	{
		for (int j = 0; j < q; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j + 1] = temp;
			}
		}
	}

	for (int q = 0; q < i; q++)
		printf("%d", arr[q]);

}