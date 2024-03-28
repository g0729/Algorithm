#include<iostream>
#include<queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	priority_queue<int, vector<int>, greater<int>>large_pq;
	priority_queue<int>low_pq;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		if (low_pq.empty())
		{
			low_pq.push(a);
		}
		else
		{
			if (i % 2 == 1)
			{
				large_pq.push(a);
			}
			else
			{
				low_pq.push(a);
			}
		}
		if (!large_pq.empty()&&large_pq.top() < low_pq.top())
		{
			int temp1 = large_pq.top();
			int temp2 = low_pq.top();
			large_pq.pop();
			low_pq.pop();
			large_pq.push(temp2);
			low_pq.push(temp1);
		}
		cout << low_pq.top() << "\n";
	}

}