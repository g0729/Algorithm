#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

int MAP[MAX][MAX];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;

queue<pair<int, int>> q;

void bfs()
{
    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(nx<0||nx>=n||ny<0||ny>=m)
            continue;

            if(MAP[nx][ny]!=-1||MAP[nx][ny]==0)
            continue;

            MAP[nx][ny]=MAP[x][y]+1;
            q.push({nx,ny});
        }
        
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int a;

            cin >> a;

            if (a == 2)
            {
                q.push({i, j});
                MAP[i][j] = 0;
            }
            else if(a==1)
            {
                MAP[i][j]=-1;
            }
            else
            {
                MAP[i][j]=0;
            }
        }
    }

    bfs();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<<MAP[i][j]<<" ";
        }
        cout<<"\n";
    }
    
}