#include<bits/stdc++.h>
using namespace std;
#define MAX 50
char graph[MAX][MAX];
int n,m;
bool visited[MAX][MAX];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
pair<int,int>start;
void dfs(int x,int y,int cnt)
{
    visited[x][y]=true;
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<0||nx>=n||ny<0||ny>=m||graph[nx][ny]!=graph[x][y])
        continue;
        if(nx==start.first&&ny==start.second&&cnt>=3)
        {
            cout<<"Yes";
            exit(0);
        }    
        if(visited[nx][ny]==true)
        continue;
        dfs(nx,ny,cnt+1);
    }
    visited[x][y]=false;
}
int main()
{
    cin>>n>>m;
    for(int i = 0;i<n;i++)
    {
        for (int q = 0; q < m; q++)
        {
            cin>>graph[i][q];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int q  = 0; q < m; q++)
        {
            if(!visited[i][q])
            {
                start={i,q};
                dfs(i,q,1);            }           
        }
    }
    cout<<"No";
}