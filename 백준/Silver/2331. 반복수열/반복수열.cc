#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 1000000

int check[MAX];
int a, p;

int cal(int &num)
{
	string s = to_string(num);

	int res = 0;

	for (int i = 0; i < s.length(); i++)
	{
		int temp = 1;

		for (int j = 0; j < p; j++)
		{
			temp *= (s[i] - '0');
		}
		res += temp;
	}
	return res;
}

void dfs(int num)
{
	check[num]++;

	int next=cal(num);

	if(check[num]==3)
		return;
	
	dfs(next);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> a >> p;

	dfs(a);

	int cnt=0;

	for (int i = 0; i < MAX; i++)
	{
		if(check[i]==1)
			cnt++;
	}
	
	cout<<cnt;
	return 0;
}