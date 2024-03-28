#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

struct TripleInt
{

	int a, b, c;
	TripleInt(int a, int b, int c) : a(a), b(b), c(c) {}
};
vector<TripleInt> v;
int parent[100001];
int n, m;

bool cmp(TripleInt a, TripleInt b)
{
	return a.c < b.c;
}

int Find(int x)
{
	if (parent[x] == x)
		return x;
	else
		return parent[x] = Find(parent[x]);
}

bool sameParent(int x, int y)
{
	x = Find(x);
	y = Find(y);

	return x == y;
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);

	if (x != y)
	{
		parent[y] = x;
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	lint res=0;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		res+=c;
		TripleInt temp(a, b, c);
		v.push_back(temp);
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 1; i <= n; i++)
	{
		parent[i]=i;
	}
	

	for (int i = 0; i < m; i++)
	{
		if (!sameParent(v[i].a, v[i].b))
		{
			Union(v[i].a, v[i].b);
			res -= v[i].c;
		}
	}

	for (int i = 2; i <= n; i++)
	{
		if(Find(1)!=Find(i))
		{
			cout<<"-1";
			return 0;
		}
	}
	
	cout << res;
	return 0;
}