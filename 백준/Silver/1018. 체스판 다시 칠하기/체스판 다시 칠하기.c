#include<stdio.h>
main()
{
	int n, m, min = 63;;
	char a[51][52];
	char first;
	int count;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		scanf("%s", a[i]);
	}

	for (int i = 0; i <= n - 8; i++)
	{

		for (int j = 0; j <= m - 8; j++)
		{
			count = 0;
			for (int q = i; q < i + 8; q++)
			{

				for (int p = j ; p < j + 8; p++)
				{
					first = 'B';
					if ((q - i) % 2 == 0)
					{
						if ((p - j) % 2 == 1 && a[q][p] == first)
							count++;
						if ((p - j) % 2 == 0 && a[q][p] != first)
							count++;
					}
					else
					{
						if ((p - j) % 2 == 1 && a[q][p] != first)
							count++;
						if ((p - j) % 2 == 0 && a[q][p] == first)
							count++;
					}
				}
			}
			if (count < min)
				min = count;
		}

	}
	for (int i = 0; i <= n - 8; i++)
	{

		for (int j = 0; j <= m - 8; j++)
		{
			count = 0;
			for (int q = i; q < i + 8; q++)
			{

				for (int p = j ; p < j + 8; p++)
				{
					first = 'W';
					if ((q - i) % 2 == 0)
					{
						if ((p - j) % 2 == 1 && a[q][p] == first)
							count++;
						if ((p - j) % 2 == 0 && a[q][p] != first)
							count++;
					}
					else
					{
						if ((p	- j) % 2 == 1 && a[q][p] != first)
							count++;
						if ((p - j) % 2 == 0 && a[q][p] == first)
							count++;
					}
				}
			}
			if (count < min)
				min = count;
		}

	}
	printf("%d", min);

}