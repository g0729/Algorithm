#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 101

int n, k, dir = 1;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int MAP[MAX][MAX];
deque<pair<int, int>> dq;

bool move()
{
    pair<int, int> head = dq.back();

    int nx = head.first + dx[dir];
    int ny = head.second + dy[dir];

    if (nx <= 0 || nx > n || ny <= 0 || ny > n)
        return false;

    for(auto it :dq)
    {
        if(it==make_pair(nx,ny))
            return false;
    }
    if (MAP[nx][ny] == 1)
    {
        MAP[nx][ny] = 0;
    }
    else
    {
        dq.pop_front();
    }
    dq.push_back({nx, ny});

    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    dq.push_back({1, 1});
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;

        MAP[a][b] = 1;
    }

    int m;
    cin >> m;
    vector<pair<int, char>> v(m);

    for (int i = 0; i < m; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    int idx = 0;

    for (int t = 1;; t++)
    {
        if (!move())
        {
            cout << t;
            break;
        }

        if (v[idx].first == t)
        {
            if (v[idx].second == 'D')
            {
                dir=(dir+3)%4;
            }
            else
            {
                dir = (dir + 1) % 4;
            }
            idx++; 
        }
    }
    return 0;
}