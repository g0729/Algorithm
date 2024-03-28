#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	deque<int>dq;
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		if (s == "push_front")
		{
			int a;
			cin >> a;
			dq.push_front(a);
			continue;
		}
		if (s == "push_back")
		{
			int a;
			cin >> a;
			dq.push_back(a);
			continue;
		}
		if (s == "pop_front")
		{
			if (dq.empty())
			{
				cout << "-1" << "\n";
				continue;
			}
			else
			{
				cout << dq.front() << "\n";
				dq.pop_front();
				continue;
			}
		}
		if (s == "pop_back")
		{
			if (dq.empty())
			{
				cout << "-1" << "\n";
				continue;
			}
			else
			{
				cout << dq.back() << "\n";
				dq.pop_back();
				continue;
			}
		}
		if (s == "size")
		{
			cout << dq.size() << "\n";
			continue;
		}
		if (s == "empty")
		{
			cout << dq.empty() << "\n";
			continue;
		}
		if (s == "front")
		{
			if (dq.empty())
			{
				cout << "-1" << "\n";
					continue;
			}
			else
			{
				cout << dq.front() << "\n";
				continue;
			}
		}
		if (s == "back")
		{
			if (dq.empty())
			{
				cout << "-1" << "\n";
				continue;
			}
			else
			{
				cout << dq.back() << "\n";
				continue;
			}
		}
		
	}
}