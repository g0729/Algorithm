#include<iostream>
using namespace std;

int main()
{
	short squ[4][4];
	bool arr[101][101] = { 0 };

	for (int i = 0; i < 4; i++)
	{
		for (int q = 0; q < 4; q++)
		{
			cin >> squ[i][q];
		}
	}	
	for (int i = 0; i < 4; i++)
	{
		for (int q = squ[i][0]; q < squ[i][2]; q++)
		{
			for (int j = squ[i][1]; j < squ[i][3]; j++)
			{
				arr[q][j] = true;
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i < 101; i++)
	{
		for (int q = 1; q < 101; q++)
		{
			if (arr[i][q])
			{
				cnt++;
			}
		}
	}
	cout << cnt;
}