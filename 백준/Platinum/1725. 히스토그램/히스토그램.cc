#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
long long arr[MAX];
long long n;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long res = 0;
	stack<long long> s;
	cin >> n;
	if (n == 0)
		exit(0);
	for (long long i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	s.push(0);
	for (long long i = 1; i < n; i++)
	{
		if (arr[i] >= arr[s.top()])
		{
			s.push(i);
		}
		else
		{
			while (!s.empty() && arr[i] < arr[s.top()])
			{
				long long h = arr[s.top()];
				s.pop();
				long long l = i;
				if (!s.empty())
				{
					l = i - s.top() - 1;
				}
				long long temp = l * h;
				res = max(res, temp);
			}
			s.push(i);
		}
	}
	while (!s.empty())
	{
		long long h = arr[s.top()];
		s.pop();
		long long l = n;
		if (!s.empty())
		{
			l = n - s.top() - 1;
		}
		long long temp = l * h;
		res = max(res, temp);
	}
	cout << res << "\n";
}