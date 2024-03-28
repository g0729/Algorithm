#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long
#define MOD 1000000007

vector<lint>v;
vector<lint>tree;

lint update(int start,int end,int node,int idx,int val)
{
	if(idx<start||idx>end)
		return tree[node];
	if(start==end)
		return tree[node]+=val;

	int mid=(start+end)/2;

	return tree[node]=update(start,mid,node*2,idx,val)+update(mid+1,end,node*2+1,idx,val);
}

lint sum(int start,int end,int node,int left,int right)
{
	if(left>end||right<start)
		return 0;
	if(left<=start&&end<=right)
		return tree[node];

	int mid=(start+end)/2;

	return sum(start,mid,node*2,left,right)+sum(mid+1,end,node*2+1,left,right);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n,m;
	cin>>n>>m;

	v=vector<lint>(n);
	tree=vector<lint>(4*n);


	for (int i = 0; i < m; i++)
	{
		int a,b,c;
		cin>>a>>b>>c;

		if(a==1)
		{
			update(0,n-1,1,b-1,c);
			v[b-1]+=c;
		}
		else
			cout<<sum(0,n-1,1,b-1,c-1)<<"\n";
	}
	
	return 0;
}