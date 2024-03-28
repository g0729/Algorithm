#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int>v;
vector<int>res;
bool sel[8];
void dfs(int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < res.size(); i++)
		{
			cout << res[i] << " ";
		}
		cout << "\n";
		return;
	}
	int a = -1;
	for (int i = 0; i < n; i++)
	{
		if (sel[i])
			continue;
		if (a == v[i])
			continue;
		a = v[i];
		sel[i] = true;
		res.push_back(v[i]);
		dfs(cnt + 1);
		sel[i] = false;
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
	dfs(0);
}