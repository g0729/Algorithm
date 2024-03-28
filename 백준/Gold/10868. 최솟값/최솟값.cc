#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long
#define MOD 1000000007

vector<int> v;
vector<int> tree;

int init(int start,int end,int node)
{
	if(start==end)
		return tree[node]=v[start];

	int mid=(start+end)/2;

	return tree[node]=min(init(start,mid,node*2),init(mid+1,end,node*2+1));
}

int search(int start,int end,int node,int left,int right)
{
	if(left>end||right<start)
		return 1e9+1;
	
	if(left<=start&&end<=right)
		return tree[node];

	int mid=(start+end)/2;

	return min(search(start,mid,node*2,left,right),search(mid+1,end,node*2+1,left,right));
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n,m;
	cin >> n>>m;

	v = vector<int>(n);
	tree = vector < int>(4 * n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	init(0,n-1,1);

	for (int i = 0; i < m; i++)
	{
		int a,b;
		cin>>a>>b;

		cout<<search(0,n-1,1,a-1,b-1)<<"\n";
	}
	
	return 0;
}