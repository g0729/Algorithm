#include<iostream>
#define MAX 1001
using namespace std;
int arr[MAX][5];
int cnt[MAX];
bool sel[MAX];
int n;
void reset()
{
	for(int i = 0; i < n; i++)
	{
		sel[i] = false;
	}
}
int selcnt()
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (sel[i] == true)
			cnt++;
	}
	return cnt;
}
int main()
{
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int q = 0; q < 5; q++)
		{
			cin >> arr[i][q];
		}
	}
	for (int i = 0; i < n; i++)
	{
		int res = 0;
		sel[i] = true;
		for (int q = 0; q < 5; q++)
		{
			for (int j = 0; j < n; j++)
			{
				if (sel[j] == true)
					continue;
				if (arr[i][q] == arr[j][q])
				{
					sel[j] = true;
				}
			}
		}
		res = selcnt()-1;
		reset();
		cnt[i] = res;
	}
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (cnt[max] < cnt[i])
			max = i;
	}
	cout << max + 1;

}