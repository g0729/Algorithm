#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;

	int R, C;

	for (int i = 1; i * i <= s.length(); i++)
	{
		if (s.length() % i == 0)
		{
			R = i;
			C = s.length() / i;
		}
	}

	vector<vector<char>> v(R, vector<char>(C));

	for (int i = 0; i < s.length(); i++)
	{
		v[i%R][i/R]=s[i];
	}
	
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout<<v[i][j];
		}
		
	}
	
	
	return 0;
}