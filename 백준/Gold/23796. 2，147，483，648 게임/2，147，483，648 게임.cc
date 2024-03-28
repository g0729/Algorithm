#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

ll MAP[8][8];
vector<ll> merge(vector<ll> &v)
{
	vector<ll> res;

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == v[i + 1] && i != v.size() - 1)
		{
			res.push_back(v[i] * 2);
			i++;
		}
		else
			res.push_back(v[i]);
	}
	return res;
}
void up()
{
	for (int i = 0; i < 8; i++)
	{
		vector<ll> temp;
		for (int j = 0; j < 8; j++)
		{
			if (MAP[j][i] != 0)
				temp.push_back(MAP[j][i]);
		}
		vector<ll> res = merge(temp);

		for (int j = 0; j < 8; j++)
		{
			if (j < res.size())
				MAP[j][i] = res[j];
			else
				MAP[j][i] = 0;
		}
	}
}
void down()
{
	for (int i = 0; i < 8; i++)
	{
		vector<ll> temp;
		for (int j = 0; j < 8; j++)
		{
			if (MAP[7 - j][i] != 0)
				temp.push_back(MAP[7 - j][i]);
		}
		vector<ll> res = merge(temp);

		for (int j = 0; j < 8; j++)
		{
			if (j < res.size())
				MAP[7 - j][i] = res[j];
			else
				MAP[7 - j][i] = 0;
		}
	}
}
void left()
{
	for (int i = 0; i < 8; i++)
	{
		vector<ll> temp;
		for (int j = 0; j < 8; j++)
		{
			if (MAP[i][j] != 0)
				temp.push_back(MAP[i][j]);
		}
		vector<ll> res = merge(temp);

		for (int j = 0; j < 8; j++)
		{
			if (j < res.size())
				MAP[i][j] = res[j];
			else
				MAP[i][j] = 0;
		}
	}
}
void right()
{
	for (int i = 0; i < 8; i++)
	{
		vector<ll> temp;
		for (int j = 0; j < 8; j++)
		{
			if (MAP[i][7 - j] != 0)
				temp.push_back(MAP[i][7 - j]);
		}
		vector<ll> res = merge(temp);

		for (int j = 0; j < 8; j++)
		{
			if (j < res.size())
				MAP[i][7 - j] = res[j];
			else
				MAP[i][7 - j] = 0;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cin >> MAP[i][j];
		}
	}
	char c;
	cin >> c;

	if (c == 'U')
		up();
	else if (c == 'D')
		down();
	else if (c == 'L')
		left();
	else
		right();
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << MAP[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}