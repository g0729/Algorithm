#include<bits/stdc++.h>
using namespace std;

int main()
{
	priority_queue<int>q;
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
			if (q.empty())
			{
				cout << "0\n";
			}
			else
			{
				cout << q.top()<<"\n";
				q.pop();
			}
		}
		else
		{
			q.push(a);
		}
	}
}