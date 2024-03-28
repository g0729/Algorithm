#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int graph[MAX][MAX];
int visited[MAX][MAX][2];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int n,m;

int bfs()
{
    queue<tuple<int,int,bool>>q;
    q.push({0,0,true});
    visited[0][0][1]=1;
    while(!q.empty())
    {
        int x=get<0>(q.front());
        int y=get<1>(q.front());
        bool broke=get<2>(q.front());
        q.pop();
        if(x==n-1&&y==m-1)
        return visited[x][y][broke];
        for(int i = 0 ; i<4;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0||nx>=n||ny<0||ny>=m)
            continue;
            if(graph[nx][ny]==1&&broke)
            {
                visited[nx][ny][0]=visited[x][y][1]+1;
                q.push({nx,ny,false});
            }
            if(graph[nx][ny]==0&&visited[nx][ny][broke]==0)
            {
                visited[nx][ny][broke]=visited[x][y][broke]+1;
                q.push({nx,ny,broke});
            }
        }
    }
    return -1;
}
int main()
{
    
    scanf("%d %d",&n,&m);
    for(int i =0 ; i<n;i++)
    {
        for(int q= 0; q<m;q++)
        {
            scanf("%1d",&graph[i][q]);
        }
    }
    int res=bfs();
    cout<<res;
    
}