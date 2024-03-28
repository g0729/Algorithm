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
	{
		if(v[start]<0)
			return tree[node]=-1;
		else if(v[start]>0)
			return tree[node]=1;
		else
			return tree[node]=0;
	}

	int mid=(start+end)/2;

	return tree[node]=init(start,mid,node*2)*init(mid+1,end,node*2+1);
}

int update(int start,int end,int node ,int idx,int val)
{
	if(idx<start||idx>end)
		return tree[node];
	
	if(start==end)
	{
		if(val<0)
			return tree[node]=-1;
		else if(val>0)
			return tree[node]=1;
		else
			return tree[node]=0;
	}

	int mid=(start+end)/2;

	return tree[node]=update(start,mid,node*2,idx,val)*update(mid+1,end,node*2+1,idx,val);
}

int search(int start,int end,int node,int left,int right)
{
	if(left>end||right<start)
		return 1;
	if(left<=start&&end<=right)
		return tree[node];

	int mid=(start+end)/2;

	return search(start,mid,node*2,left,right)*search(mid+1,end,node*2+1,left,right);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while(1)
	{
		int n,m;
		cin>>n>>m;

		if(cin.eof())
			break;
		
		v=vector<int>(n);
		tree=vector<int>(4*n);

		for (int i = 0; i < n; i++)
			cin>>v[i];

		init(0,n-1,1);

		for (int i = 0; i < m; i++)
		{
			char a;
			int b,c;
			cin>>a>>b>>c;

			if(a=='C')
			{
				update(0,n-1,1,b-1,c);
				v[b-1]=c;
			}
			else
			{
				int temp=search(0,n-1,1,b-1,c-1);
				if(temp==0)
					cout<<"0";
				else if(temp>0)
					cout<<"+";
				else
					cout<<"-";
			}
		}
		cout<<"\n";
	}
	return 0;
}