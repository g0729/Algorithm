#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 1000001

struct IntT
{
	int arr[3] = {
		0,
	};

	int sum()
	{
		return arr[0] + arr[1] + arr[2];
	}
};

IntT dp[MAX];
bool operator<(IntT &a, IntT &b)
{
	if (a.sum() < b.sum())
		return true;
	else if (a.sum() > b.sum())
		return false;
	else
	{
		if (a.arr[0] > b.arr[0])
			return true;
		else if (a.arr[0] < b.arr[0])
			return false;
		else if (a.arr[1] > b.arr[1])
			return true;
		else if (a.arr[1] < b.arr[1])
			return false;
		else if (a.arr[2] > b.arr[2])
			return true;
		else if (a.arr[2] < b.arr[2])
			return false;
		else
			return true;
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	dp[3].arr[0] = 1;
	dp[5].arr[1] = 1;
	dp[8].arr[2] = 1;
	dp[6].arr[0] = 2;

	for (int i = 9; i < MAX; i++)
	{
		if (dp[i - 3].sum() != 0)
		{
			IntT temp = dp[i - 3];
			temp.arr[0] += 1;
			if (dp[i].sum() == 0)
				dp[i] = temp;
			else if (temp < dp[i])
				dp[i] = temp;
		}
		if (dp[i - 5].sum() != 0)
		{
			IntT temp = dp[i - 5];
			temp.arr[1] += 1;
			if (dp[i].sum() == 0)
				dp[i] = temp;
			else if (temp < dp[i])
				dp[i] = temp;
		}
		if (dp[i - 8].sum() != 0)
		{
			IntT temp = dp[i - 8];
			temp.arr[2] += 1;
			if (dp[i].sum() == 0)
				dp[i] = temp;
			else if (temp < dp[i])
				dp[i] = temp;
		}
	}
	while (t--)
	{
		int n;
		cin >> n;

		if (dp[n].sum() == 0)
		{
			cout << "-1";
		}
		else
		{
			cout<<string(dp[n].arr[0],'3')<<string(dp[n].arr[1],'5')<<string(dp[n].arr[2],'8');
		}
		cout << "\n";
	}
	return 0;
}
