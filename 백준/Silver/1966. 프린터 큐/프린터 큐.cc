#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n, k;
		cin >> n >> k;
		int cnt = 0;
		queue<pair<int, int>>q;
		priority_queue<int>pq;
		for (int j = 0; j < n; j++)
		{
			int a;
			cin >> a;
			pq.push(a);
			q.push({ a, j });
		}
		while (1)
		{
			if (q.front().first != pq.top())
			{
				q.push({ q.front().first, q.front().second });
				q.pop();
			}
			else
			{
				if (q.front().second == k)
				{
					cnt++;
					cout << cnt<<endl;
					break;
				}
				else
				{
					cnt++;
					pq.pop();
					q.pop();
				}
			}
		}
	}

}