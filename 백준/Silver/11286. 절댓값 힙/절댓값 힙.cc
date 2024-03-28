#include<bits/stdc++.h>
using namespace std;

int main()
{
	priority_queue<int>q_mi;
	priority_queue<int,vector<int>,greater<int>>q_pl;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		if (a == 0)
		{
			int res;
			if (q_pl.empty())
			{
				if (q_mi.empty())
				{
					cout << "0\n";
					continue;
				}
				else
				{
					res = q_mi.top();
					q_mi.pop();
					cout << res << "\n";
					continue;
				}
			}
			if (q_mi.empty())
			{
				if (q_pl.empty())
				{
					cout << "0\n";
					continue;
				}
				else
				{
					res = q_pl.top();
					cout << res << "\n";
					q_pl.pop();
					continue;
				}
			}
			if (q_pl.top() == abs(q_mi.top()))
			{
				res = q_mi.top();
				cout << res << "\n";
				q_mi.pop();
				continue;
			}
			else
			{
				res = q_pl.top() < abs(q_mi.top()) ? q_pl.top() : q_mi.top();
				cout << res << "\n";
			}
			if (res > 0)
			{
				q_pl.pop();
			}
			else
			{
				q_mi.pop();
			}
		}
		else
		{
			if (a > 0)
			{
				q_pl.push(a);
			}
			else
			{
				q_mi.push(a);
			}
		}
	}
}