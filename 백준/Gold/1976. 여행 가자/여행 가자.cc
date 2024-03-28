#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long
#define MOD 1000000007

vector<int> parent;

int find(int x)
{
	if (parent[x] == x)
		return x;

	return parent[x] = find(parent[x]);
}
void merge(int x, int y)
{
	x = find(x);
	y = find(y);

	if (x == y)
		return;
	parent[y] = x;
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
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	parent = vector<int>(n+1);

	for (int i = 0; i < parent.size(); i++)
	{
		parent[i] = i;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int a;
			cin>>a;
			if(a==1)
				merge(i,j);
		}
		
	}
	
	int first;
	cin>>first;

	bool flag=true;
	for (int i = 0; i < m-1; i++)
	{
		int a;
		cin>>a;

		if(!isUnion(first,a))
			flag=false;
	}
	
	if(flag)
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}