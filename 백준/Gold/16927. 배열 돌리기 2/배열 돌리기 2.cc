#include <bits/stdc++.h>
using namespace std;

int MAP[300][300];
int CMAP[300][300];

int main()
{

	ios_base::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	
	int n, m;
	int r;

	cin >> n >> m >> r;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> MAP[i][j];
		}
	}

	int minLength = min(n, m);

	for (int i = 0; i < minLength / 2; i++)
	{
		int length = 2 * (n - 2*i) + 2 * (m - 2*i) - 4;

		int move = r % length;

		vector<int> v;

		for (int j = i; j < m - i; j++)
			v.push_back(MAP[i][j]);
		for (int j = i + 1; j < n - i - 1; j++)
			v.push_back(MAP[j][m - i - 1]);
		for (int j = m - i - 1; j >= i; j--)
			v.push_back(MAP[n - i - 1][j]);
		for (int j = n - i - 2; j >= i + 1; j--)
			v.push_back(MAP[j][i]);

		for (int j = i; j < m - i; j++)
		{
			CMAP[i][j] = v[move];
			move++;
			if (move == v.size())
				move = 0;
		}
		for (int j = i + 1; j < n - i - 1; j++)
		{
			CMAP[j][m - i - 1] = v[move];
			move++;
			if (move == v.size())
				move = 0;
		}
		for (int j = m - i - 1; j >= i; j--)
		{
			CMAP[n - i - 1][j] = v[move];
			move++;
			if (move == v.size())
				move = 0;
		}

		for (int j = n - i - 2; j >= i + 1; j--)
		{
			CMAP[j][i] = v[move];
			move++;
			if (move == v.size())
				move = 0;
		}

	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout<<CMAP[i][j]<<" ";
		}
		cout<<"\n";
	}
	
}