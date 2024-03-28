#include<stdio.h>
int main()
{
	int arr[21][21][21];
	for (int i = 0; i <21 ; i++)
		for (int j = 0; j < 21; j++)
		{
			arr[0][i][j] = 1;
			arr[i][0][j] = 1;
			arr[i][j][0] = 1;
		}
	for(int a= 1;a<21;a++)
		for (int b = 1; b < 21; b++)
			for (int c = 1; c < 21; c++)
			{
				if (a < b && b < c)
					arr[a][b][c] = arr[a][b][c - 1] + arr[a][b - 1][c - 1] - arr[a][b - 1][c];
				else
					arr[a][b][c] = arr[a - 1][b][c] + arr[a - 1][b - 1][c] + arr[a - 1][b][c - 1] - arr[a - 1][b - 1][c - 1];
			}
	while (1)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if (a == -1 && b == -1&&c == -1)
		{
			break;
		}
		if (a <= 0 || b <= 0 || c <= 0)
			printf("w(%d, %d, %d) = 1\n", a, b, c);
		else if (a > 20 || b > 20 || c > 20)
			printf("w(%d, %d, %d) = %d\n", a, b, c, arr[20][20][20]);
		else
			printf("w(%d, %d, %d) = %d\n", a, b, c, arr[a][b][c]);
	}
}