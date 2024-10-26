#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int r, c;
vector<vector<int>> v;
vector<vector<int>> desrc;
vector<vector<bool>> visited;

vector<int> get_dirs(int num)
{
    vector<int> temp;

    for (int i = 0; i < 4; i++)
    {
        if (num & 1)
            temp.push_back(i);
        num >>= 1;
    }

    return temp;
}

bool bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    vector<bool> nums(10);
    nums[v[x][y]] = true;
    int size = 1;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        vector<int> dirs = get_dirs(desrc[x][y]);

        for (int i = 0; i < dirs.size(); i++)
        {
            int nx = x + dx[dirs[i]];
            int ny = y + dy[dirs[i]];
            int nvalue = v[nx][ny];

            if (visited[nx][ny])
                continue;
            if (nums[nvalue])
                return false;
            nums[nvalue] = true;
            visited[nx][ny] = true;
            q.push({nx, ny});
            size++;
        }
    }
    for (int i = 1; i < 10; i++)
    {
        if (i <= size && !nums[i])
            return false;
        if (i > size && nums[i])
            return false;
    }

    return true;
}

bool is_valid(int x, int y)
{
    int value = v[x][y];

    for (int i = max(0, x - value); i <= min(r - 1, x + value); i++)
    {
        if (i != x && v[i][y] == value)
            return false;
    }
    for (int i = max(0, y - value); i <= min(c - 1, y + value); i++)
    {
        if (i != y && v[x][i] == value)
            return false;
    }

    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> r >> c;
        v = vector<vector<int>>(r, vector<int>(c));
        desrc = vector<vector<int>>(r, vector<int>(c));
        visited = vector<vector<bool>>(r, vector<bool>(c));
        for (int i = 0; i < r; i++)
        {
            string s;
            cin >> s;
            for (int j = 0; j < c; j++)
                v[i][j] = s[j] - '0';
        }
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> desrc[i][j];
            }
        }
        bool flag = true;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (!is_valid(i, j))
                    flag = false;
                if (!visited[i][j])
                {
                    if (!bfs(i, j))
                        flag = false;
                }
            }
        }

        if (flag)
            cout << "valid";
        else
            cout << "invalid";
        cout << "\n";
    }

    return 0;
}