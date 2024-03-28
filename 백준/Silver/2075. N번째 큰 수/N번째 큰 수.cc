#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	priority_queue<int, vector<int>, greater<int>> pq;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		pq.push(a);
	}
	int cnt = n;
	for (int i = 0; i < n - 1; i++)
	{
		for (int q = 0; q < n; q++)
		{
			int a;
			cin >> a;
			if (pq.top() > a)
				continue;
			if (pq.top() < a)
			{
				pq.push(a);
				pq.pop();
			}
		}
	}
	int res = pq.top();
	cout << res;
}