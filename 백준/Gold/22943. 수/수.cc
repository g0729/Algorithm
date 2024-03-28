#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
bool prime[MAX];
bool sel[10];
int cnt = 0;
long long k, m;
void eratos()
{
	prime[0] = prime[1] = true;
	for (int i = 2; i * i < MAX; i++)
	{
		if (prime[i] == false)
		{
			for (int j = i * i; j < MAX; j += i)
			{
				prime[j] = true;
			}
		}
	}
}
bool check1(int target)
{
	for (int i = 2; i <= target / 2; i++)
	{
		if (!prime[i] && !prime[target - i])
		{
			if (i != target - i)
				return true;
		}
	}
	return false;
}
bool check2(int target)
{
	for (int i = 2; i * i <= target; i++)
	{
		if (prime[i] == false)
		{
			if (target % i == 0)
			{
				if (!prime[target / i])
					return true;
			}
		}
	}
	return false;
}
void dfs(long long sum, int n)
{
	if (n == k)
	{
		long long temp=sum;
		while(temp%m==0)
		{
			temp/=m;
		}
		if (check1(sum) && check2(temp))
			cnt++;
		return;
	}
	for (int i = 0; i < 10; i++)
	{
		if (n == 0 && i == 0)
			continue;
		if (sel[i])
			continue;
		sel[i] = true;
		dfs(sum * 10 + i, n + 1);
		sel[i] = false;
	}
}
int main()
{
	cin >> k >> m;
	eratos();
	dfs(0,0);
	cout<<cnt;
	
}