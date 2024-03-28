#include<stdio.h>
main()
{
	char arr[80] = "";
	int n;
	int q,count, temp;
	q = count = temp = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%s", arr);
		while (arr[q] != 0)
		{
			if (arr[q] == 'O')
			{
				temp++;
				count += temp;
			}
			else
				temp = 0;
			q++;
		}
		printf("%d\n", count);
		count = temp = q = 0;
	}
}