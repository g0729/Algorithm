#include <stdio.h>

int main(int argc, char** argv)
{
	int test_times;
	int level, room_num;
	
	int apt_num[15][14];
	for (int i = 0; i < 14; i++)
	{
		apt_num[0][i] = i + 1;
	}
	for (int i = 1; i < 15; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			apt_num[i][j] = 0;
			for (int k = 0; k <= j; k++)
			{
				apt_num[i][j] += apt_num[i - 1][k];
			}
		}
	}

	scanf("%d", &test_times);
	for (int i = 0; i < test_times; i++)
	{
		scanf("%d", &level);
		scanf("%d", &room_num);

		printf("%d\n", apt_num[level][room_num - 1]);
	}

	return 0;
}