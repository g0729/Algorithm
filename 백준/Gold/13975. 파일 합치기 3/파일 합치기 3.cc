#include<bits/stdc++.h>
using namespace std;
priority_queue<long long, vector<long long>, greater<long long>>pq;

int main()
{
	int t;
	cin >> t;
	for (int j = 0; j < t; j++)
	{
		int n;
		cin >> n;
		long long sum = 0;
		long long temp = 0;
		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			pq.push(a);
		}
		while (!pq.empty())
		{
			temp = pq.top();
			pq.pop();
			if (pq.empty())
			{
			}
			else
			{
				temp += pq.top();
				pq.pop();
				pq.push(temp);
				sum += temp;
			}
		}
		cout << sum << endl;
	}
}