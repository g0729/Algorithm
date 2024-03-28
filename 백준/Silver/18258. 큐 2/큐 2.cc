#include<iostream>
#include<queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	queue<int>q;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		if (s == "push")
		{
			int a;
			cin >> a;
			q.push(a);
			continue;
		}
		 if (s == "pop")
		{
			if (q.empty())
			{
				cout << "-1\n";
				continue;
			}
			else
			{
				cout << q.front() << "\n";
				q.pop();
				continue;
			}
		}
		if (s == "size")
		{
			cout << q.size() << "\n";
			continue;
		}
		if (s == "empty")
		{
			if (q.empty())
			{
				cout << "1\n";
				continue;
			}
			else
			{
				cout << "0\n";
				continue;
			}
		}
		if (s == "front")
		{
			if (q.empty())
			{
				cout << "-1\n";
				continue;
			}
			else
			{
				cout << q.front() << "\n";
				continue;
			}
		}
		if (s == "back")
		{
			if (q.empty())
			{
				cout << "-1\n";
				continue;
			}
			else
			{
				cout << q.back() << "\n";
				continue;
			}
		}
	}
}