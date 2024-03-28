#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int city[50][50];
int n, m;
int res = 10000;
bool sel[13];
vector<pair<int, int>> v_home;
vector<pair<int, int>> v_chi;
vector<pair<int, int>> cv_chi;
int check()
{
	int sum = 0;

	for (int i = 0; i < v_home.size(); i++)
	{
		int min = 100;
		for (int q = 0; q < v_chi.size(); q++)
		{
			if (v_chi[q].first == 0)
				continue;
			int len = abs(v_home[i].first - v_chi[q].first) + abs(v_home[i].second - v_chi[q].second);
			if (min > len)
			{
				min = len;
			}
		}
		sum += min;
	}
	return sum;
}
void DFS(int idx,int a)
{

	if (a == m)
	{
		if (res > check())
		{
			res = check();
		}	

		return;
	}
	for (int i = idx; i < v_chi.size(); i++)
	{
		if (sel[i] == true)
			continue;
		sel[i] = true;
		v_chi[i] = {0,0};
		DFS(i, a - 1);
		sel[i] = false;
		v_chi[i] = { cv_chi[i].first,cv_chi[i].second };
		
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int  i = 0; i < n; i++)
	{
		for (int q = 0; q < n; q++)
		{
			cin >> city[i][q];
			if (city[i][q] == 1)
			{
				v_home.push_back({ i+1,q+1 });
			}
			if (city[i][q] == 2)
			{
				v_chi.push_back({ i+1,q+1 });
			}
		}
	}
	
	cv_chi.resize(v_chi.size());
	copy(v_chi.begin(), v_chi.end(), cv_chi.begin());
	DFS(0, v_chi.size());
	cout << res;
}