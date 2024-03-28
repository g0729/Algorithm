#include <bits/stdc++.h>
using namespace std;
#define MAX 987654321
#define lint long long

int MAP[10][10];
bool visited[10][10];
int n;
int res = 1e9;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int cnt, int sum)
{
    if (cnt == 3)
    {
        res=min(sum,res);
        return ;
    }

    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < n - 1; j++)
        {
            if (visited[i][j] == false)
            {
                bool flag = false;
                for (int k = 0; k < 4; k++)
                {
                    int x = i + dx[k];
                    int y = j + dy[k];

                    if (visited[x][y] == true)
                    {
                        flag = true;
                        break;
                    }
                }
                if (!flag)
                {
                    int csum = sum;
                    csum += MAP[i][j];
                    visited[i][j] = true;
                    for (int k = 0; k < 4; k++)
                    {
                        int x = i + dx[k];
                        int y = j + dy[k];

                        visited[x][y] = true;
                        csum += MAP[x][y];
                    }
                    dfs(cnt+1,csum);
                    visited[i][j]=false;
                    for (int k = 0; k < 4; k++)
                    {
                        int x = i + dx[k];
                        int y = j + dy[k];

                        visited[x][y] = false;
                    }
                }
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> MAP[i][j];
        }
    }
    dfs(0,0);

    cout<<res;
    return 0;
}