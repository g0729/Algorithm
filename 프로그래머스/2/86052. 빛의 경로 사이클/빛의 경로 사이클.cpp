#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n, m;
vector<vector<vector<int>>> visited;
vector<vector<vector<bool>>> finished;
int len, idx;

void dfs(int x, int y, int dir, vector<string> &grid)
{
    visited[x][y][dir] = idx++;
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    int ndir;
    if (nx < 0)
        nx = n - 1;
    else if (nx >= n)
        nx = 0;
    if (ny < 0)
        ny = m - 1;
    else if (ny >= m)
        ny = 0;
    if (grid[nx][ny] == 'S')
        ndir = dir;
    else if (grid[nx][ny] == 'L')
        ndir = (dir + 3) % 4;
    else
        ndir = (dir + 1) % 4;
    if (visited[nx][ny][ndir] == -1)
        dfs(nx, ny, ndir, grid);
    else if (!finished[nx][ny][ndir])
        len = visited[x][y][dir] - visited[nx][ny][ndir] + 1;
    finished[x][y][dir] = true;
}
vector<int> solution(vector<string> grid)
{
    vector<int> answer;
    n = grid.size();
    m = grid[0].length();
    visited = vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(4, -1)));
    finished = vector<vector<vector<bool>>>(n, vector<vector<bool>>(m, vector<bool>(4)));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                if (!finished[i][j][k])
                {
                    len = 0;
                    dfs(i, j, k, grid);
                    answer.push_back(len);
                }
            }
        }
    }
    sort(answer.begin(),answer.end());
    return answer;
}