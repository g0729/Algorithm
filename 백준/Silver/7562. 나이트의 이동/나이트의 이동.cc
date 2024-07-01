#include <iostream>
#include <queue>
using namespace std;

int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {1, -1, 2, -2, 2, -2, 1, -1};

int mat[300][300];
bool visited[300][300];

int main()
{
    queue<pair<int, int>> q; // 페어 큐 쓰는거 익숙해져야할듯
    int n, testcase, x, y, ex, ey;
    cin >> testcase;

    while (testcase--)
    {

        cin >> n;
        cin >> x >> y;
        cin >> ex >> ey;

        visited[x][y] = true;
        mat[x][y] = 0;
        mat[ex][ey] = 0;
        q.push(make_pair(x, y));

        while (!q.empty())
        {
            x = q.front().first;
            y = q.front().second;
            q.pop();

            for (int i = 0; i < 8; i++)
            {
                if (x + dx[i] >= 0 && x + dx[i] < n && y + dy[i] >= 0 && y + dy[i] < n)
                {
                    if (!visited[x + dx[i]][y + dy[i]])
                    {
                        mat[x + dx[i]][y + dy[i]] = mat[x][y] + 1;
                        visited[x + dx[i]][y + dy[i]] = 1;
                        // cout<<x+dx[i]<<" ,"<<y+dy[i]<<'='<<mat[x+dx[i]][y+dy[i]]<<" "<<x<<y<<endl;
                        q.push(make_pair(x + dx[i], y + dy[i]));
                    }
                }
            }

            if (mat[ex][ey] != 0)
            {
                cout << mat[ex][ey] << "\n";
                break;
            }
        }
        if (mat[ex][ey] == 0)
        {
            cout << mat[ex][ey] << "\n";
        }
        fill(visited[0], visited[300], false);
        fill(mat[0], mat[300], 0);
        // memset(visited, false, sizeof(visited));
        // memset(mat, 0, sizeof(mat));
        while (!q.empty())
            q.pop();
    }

    return 0;
}