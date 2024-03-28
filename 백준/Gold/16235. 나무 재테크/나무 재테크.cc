#include<bits/stdc++.h>
using namespace std;
#define MAX 11
int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

vector<int>tree[MAX][MAX];
int add[MAX][MAX];
int MAP[MAX][MAX];
int n,m,k;
void breeding(int x,int y)
{
	for(int  i= 0 ; i<8;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx>=1&&nx<=n&&ny>=1&&ny<=n)
		tree[nx][ny].push_back(1);
	}
}
void spring_summer()
{
	for (int i = 1; i <= n; i++)
	{
		for (int q = 1; q <= n; q++)
		{
			if(tree[i][q].size()==0)
			continue;
			vector<int>temp;
			int sum=0;
			sort(tree[i][q].begin(),tree[i][q].end());
			for(int j =0; j<tree[i][q].size();j++)
			{
				int age=tree[i][q][j];
				if(MAP[i][q]>=age)
				{
					MAP[i][q]-=age;
					temp.push_back(age+1);
				}
				else
				{
					sum+=age/2;
				}
			}
			tree[i][q].clear();
			for(int j =0;j<temp.size();j++)
			{
				tree[i][q].push_back(temp[j]);
			}
			MAP[i][q]+=sum;
		}
	}
}
void fall()
{
	for (int i = 1; i <=n; i++)
	{
		for (int q = 1; q <=n; q++)
		{
			if(tree[i][q].size()==0)
			continue;
			for(int j = 0 ; j<tree[i][q].size();j++)
			{
				if(tree[i][q][j]%5==0)
				{
					breeding(i,q);
				}
			}
		}
		
	}
}
void winter()
{
	for (int i = 1; i <= n; i++)
	{
		for (int q = 1; q <=n; q++)
		{
			MAP[i][q]+=add[i][q];
		}
		
	}
	
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;

	for (int i = 1; i <= n; i++)
	{
		for (int q = 1; q <= n; q++)
		{
			cin>>add[i][q];
			MAP[i][q]=5;
		}
	}
	for(int i = 0;i<m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		tree[a][b].push_back(c);
	}
	for(int i =0; i<k;i++)
	{
		spring_summer();
		fall();
		winter();
	}
	int res=0;
	for (int i = 1; i <= n; i++)
	{
		for (int q = 1; q <= n; q++)
		{
			if(tree[i][q].size()==0)
			continue;
			res+=tree[i][q].size();
		}
	}
	cout<<res;
}
