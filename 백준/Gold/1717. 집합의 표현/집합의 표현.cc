#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long
#define MOD 1000000007
vector<int> parent;

int find(int x)
{
	if(parent[x]==x)
		return x;
	else
		return parent[x]=find(parent[x]);
}
void merge(int x,int y)
{
	x=find(x);
	y=find(y);

	if(x==y)
		return;
	parent[y]=x;
}
bool isUnion(int x,int y)
{
	x=find(x);
	y=find(y);

	if(x==y)
		return true;
	else
		return false;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;

	parent= vector<int>(n + 1);
	for (int i = 0; i < parent.size(); i++)
	{
		parent[i] = i;
	}
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if(a==0)
			merge(b,c);
		else
		{
			if(isUnion(b,c))
				cout<<"YES\n";
			else
				cout<<"NO\n";
		}
	}

	return 0;
}