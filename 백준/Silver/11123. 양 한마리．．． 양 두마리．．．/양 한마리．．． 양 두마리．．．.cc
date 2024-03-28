#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
char MAP[100][100];
bool visited[100][100];
int h,w;

void bfs(int x,int y)
{
    queue<pair<int,int>>q;

    q.push({x,y});
    visited[x][y]=true;

    while(!q.empty())
    {
        x=q.front().first;
        y=q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(nx<0||ny<0||nx>=h||ny>=w)
            continue;
            if(visited[nx][ny]==true)
            continue;
            if(MAP[nx][ny]=='.')
            continue;
            visited[nx][ny]=true;
            q.push({nx,ny});
        }
        
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;

    while(t--)
    {
        cin>>h>>w;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin>>MAP[i][j];
            }
        }

        int cnt=0;

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if(MAP[i][j]=='#'&&visited[i][j]==false)
                {
                    bfs(i,j);
                    cnt++;
                }
            }
            
        }
        cout<<cnt<<"\n";
        memset(visited,0,sizeof(visited));
    }

    
    return 0;
}