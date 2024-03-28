#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long
#define MOD 1000000007

vector<int> v;
vector<pair<int, int>> tree;

pair<int,int> operator +(pair<int,int>a,pair<int,int>b)
{
	pair<int,int>temp;
	temp.first=a.first+b.first;
	temp.second=a.second+b.second;

	return temp;
} 
pair<int, int> init(int start, int end, int node)
{
	if (start == end)
	{
		if (v[start] % 2 == 1)
			return tree[node]={0,1};
		else
			return tree[node]={1,0};
	}

	int mid=(start+end)/2;

	return tree[node]=init(start,mid,node*2)+init(mid+1,end,node*2+1);
}
pair<int,int> update(int start,int end,int node,int idx,int val)
{
	if(idx<start||idx>end)
		return tree[node];
	
	if(start==end)
	{
		if(val%2==1)
			return tree[node]={0,1};
		else
			return tree[node]={1,0};
	}

	int mid=(start+end)/2;

	return tree[node]=update(start,mid,node*2,idx,val)+update(mid+1,end,node*2+1,idx,val);
}

int search(int start,int end,int node,int left,int right,int pairity)
{
	if(left>end||right<start)
		return 0;
	if(left<=start&&end<=right)
	{
		if(pairity==2)
			return tree[node].first;
		else
			return tree[node].second;
	}
	
	int mid=(start+end)/2;

	return search(start,mid,node*2,left,right,pairity)+search(mid+1,end,node*2+1,left,right,pairity);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;

	v = vector<int>(n);
	tree = vector<pair<int, int>>(4 * n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	
	init(0,n-1,1);

	int m;
	cin>>m;

	for (int i = 0; i < m; i++)
	{
		int a,b,c;
		cin>>a>>b>>c;

		if(a==1)
			update(0,n-1,1,b-1,c);
		else
			cout<<search(0,n-1,1,b-1,c-1,a)<<"\n";
	}
	
	return 0;
}