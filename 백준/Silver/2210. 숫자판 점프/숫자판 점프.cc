#include <bits/stdc++.h>
using namespace std;

char MAP[5][5];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
vector<string>res;
void dfs(int x,int y, int depth,string sum)
{
	if(depth==5)
	{
		res.push_back(sum);
		return;
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(nx<0||nx>=5||ny<0||ny>=5)
			continue;
			string temp=sum+MAP[nx][ny];
			dfs(nx,ny,depth+1,temp);
		}
		
	}
}
int main()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin>>MAP[i][j];
		}
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			string temp;
			temp.push_back(MAP[i][j]);
			dfs(i,j,0,temp);
		}
	}
	
	sort(res.begin(),res.end());
	res.erase(unique(res.begin(),res.end()),res.end());

	cout<<res.size();
}
