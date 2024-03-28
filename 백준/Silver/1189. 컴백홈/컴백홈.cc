#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

char MAP[5][5];
bool visited[5][5];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int r,c,k;
int res;
void dfs(int x,int y,int cnt)
{
    if(cnt==k)
    {
        if(x==0 &&y==c-1)
        res++;

        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];

        if(nx<0||ny<0||nx>=r||ny>=c)
        continue;
        if(visited[nx][ny])
        continue;
        if(MAP[nx][ny]=='T')
        continue;

        visited[nx][ny]=true;
        dfs(nx,ny,cnt+1);
        visited[nx][ny]=false;
    }
    
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>r>>c>>k;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin>>MAP[i][j];
        }
    }
    
    visited[r-1][0]=true;
    dfs(r-1,0,1);  

    cout<<res; 
    return 0;
}