#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long
#define MOD 1000000007

vector<int> v;
vector<pair<int, int>> tree;

pair<int,int> min(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
		return a.second<b.second?a:b;

	return a.first < b.first?a:b;
}
pair<int, int> init(int start, int end, int node)
{
	if (start == end)
		return tree[node] = {v[start], start};

	int mid = (start + end) / 2;

	return tree[node] = min(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}

pair<int, int> search(int start, int end, int node, int left, int right)
{
	if (left > end || right < start)
		return {1e9+1, 1};

	if (left <= start && end <= right)
		return tree[node];

	int mid = (start + end) / 2;

	return min(search(start,mid,node*2,left,right),search(mid+1,end,node*2+1,left,right));
}

pair<int,int> update(int start,int end,int node,int idx,int val)
{
	if(idx<start||idx>end)
		return tree[node];
	if(start==end)
		return tree[node]={val,idx};
	
	int mid=(start+end)/2;

	return tree[node]=min(update(start,mid,node*2,idx,val),update(mid+1,end,node*2+1,idx,val));
	
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	v = vector<int>(n);
	tree = vector<pair<int,int>>(4 * n);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	int m;
	cin>>m;

	init(0,n-1,1);

	for (int i = 0; i < m; i++)
	{
		int a,b,c;

		cin>>a>>b>>c;

		if(a==2)
			cout<<search(0,n-1,1,b-1,c-1).second+1<<"\n";
		else
		{
			update(0,n-1,1,b-1,c);
			v[b-1]=c;
		}
	}
	
	return 0;
}