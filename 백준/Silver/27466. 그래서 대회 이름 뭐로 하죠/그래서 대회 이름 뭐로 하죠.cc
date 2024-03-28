#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	string conson = "AEIOU";
	int cnt = 0;
	int Del = 0;

	stack<char> res;
	for (int i = s.length()-1; i >= 0; i--)
	{
		if (cnt == 0)
		{
			bool flag = false;
			for (int j = 0; j < conson.length(); j++)
			{
				if (s[i] == conson[j])
				{
					flag = true;
				}
			}

			if (flag)
				Del++;
			else
			{
				cnt++;
				res.push(s[i]);
			}
		}
		else if (cnt == 1 || cnt == 2)
		{
			if (s[i] == 'A')
			{
				res.push(s[i]);
				cnt++;
			}
			else
			{
				Del++;
			}
		}
		else if(cnt>=3)
		{
			if(Del<n-m)
			{
				Del++;
			}
			else
			{
				res.push(s[i]);
			}
		}
		if(Del>n-m)
		{
			cout<<"NO";
			return 0;
		}
	}

	if(cnt<3)
	{
		cout<<"NO";
		return 0;
	}

	cout<<"YES\n";

	while(!res.empty())
	{
		cout<<res.top();
		res.pop();
	}
	return 0;
}