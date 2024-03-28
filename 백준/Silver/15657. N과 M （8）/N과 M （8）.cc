#include<bits/stdc++.h>
using namespace std;
vector<int>v;
vector<int>res;
int n, m;

void dfs(int idx,int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < res.size(); i++)
		{
			cout << res[i] << " ";
		}
		cout << "\n";
		return ;
	}
	for (int i = idx; i < v.size(); i++)
	{
		res.push_back(v[i]);
		dfs(i, cnt + 1);
		res.pop_back();
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	dfs(0, 0);
}