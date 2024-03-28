#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long
#define MOD 1000000007
vector<int> parent(300001);
int find(int x)
{
	if (parent[x] == x)
		return x;
	return parent[x] = find(parent[x]);
}
bool isUnion(int x, int y)
{
	x = find(x);
	y = find(y);

	if (x == y)
		return true;
	else
		return false;
}
void merge(int x, int y)
{
	x = find(x);
	y = find(y);

	parent[y] = x;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n + 1; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < n-2; i++)
	{
		int a, b;
		cin >> a >> b;
		merge(a, b);
	}

	for (int i = 2; i <= n; i++)
	{
		if (!isUnion(1, i))
		{
			cout << "1 " << i;
			break;
		}
	}

	return 0;
}