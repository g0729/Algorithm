#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	deque<int> dq;
	int arr[50];
	for (int i = 1; i <= n; i++)
	{
		dq.push_back(i);
	}
	for (int i = 0; i < m; i++)
	{
		cin >> arr[i];
	}
	int now = 0;
	int cnt = 0;
	while (m--)
	{
		int find;
		for (int i = 0; i < dq.size(); i++)
		{
			if (dq[i] == arr[now])
			{
				find = i;
				break;
			}
		}
		if (dq.size() / 2 < find)
		{
			while (1)
			{
				if (dq.front() == arr[now])
				{
					now++;
					dq.pop_front();
					break;
				}
					cnt++;
					dq.push_front(dq.back());
					dq.pop_back();
			}
		}
		else
		{
			while (1)
			{
				if (dq.front() == arr[now])
				{
					now++;
					dq.pop_front();
					break;
				}
					cnt++;
					dq.push_back(dq.front());
					dq.pop_front();
			}
		}
	}
	cout<<cnt;
}