#include <bits/stdc++.h>
using namespace std;
vector<string> v;
int n, l;
bool check(string s)
{
	for (int i = 1; i < n; i++)
	{
		int cnt = 0;

		for (int j = 0; j < l; j++)
		{
			if (v[i][j] != s[j])
			{
				cnt++;
				if (cnt >= 2)
					return false;
			}
		}
	}
	return true;
}

int main()
{
	cin >> n >> l;

	for (int i = 0; i < n; i++)
	{
		string s;

		cin >> s;

		v.push_back(s);
	}

	for(int i = 0 ; i<l;i++)
	{
		for (int j = 0; j < 26; j++)
		{
			string temp=v[0];
			temp[i]='A'+j;
			if(check(temp))
			{
				cout<<temp;
				return 0;
			}
		}
	}

	cout<<"CALL FRIEND";
}