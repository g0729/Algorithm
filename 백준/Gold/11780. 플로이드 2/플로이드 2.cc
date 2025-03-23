#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
vector<vector<int>> edges(101, vector<int>(101));
vector<vector<int>> costs(101, vector<int>(101));
vector<vector<int>> middle(101, vector<int>(101));

void find_path(int start, int end, vector<int> &path)
{
    if (middle[start][end] == 0)
    {
        path.push_back(start);
        path.push_back(end);
        return;
    }

    int mid = middle[start][end];

    find_path(start, mid, path);
    find_path(mid, end, path);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (edges[a][b] == 0)
            edges[a][b] = c;
        else
            edges[a][b] = min(edges[a][b], c);
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (i == j)
                costs[i][j] = 0;
            else if (edges[i][j] == 0)
                costs[i][j] = INF;
            else
                costs[i][j] = edges[i][j];
        }
    }

    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < n + 1; j++)
            for (int k = 1; k < n + 1; k++)
            {
                if (costs[j][k] > costs[j][i] + costs[i][k])
                {
                    costs[j][k] = costs[j][i] + costs[i][k];
                    middle[j][k] = i;
                }
            }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (costs[i][j] == INF)
                cout << "0";
            else
                cout << costs[i][j];
            cout << " ";
        }
        cout << "\n";
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (costs[i][j] == INF || i == j)
            {
                cout << "0\n";
                continue;
            }
            vector<int> temp;
            find_path(i, j, temp);
            vector<int> path;
            path.push_back(temp[0]);
            for (int i = 1; i < temp.size(); i++)
            {
                if (temp[i] == temp[i - 1])
                    continue;
                path.push_back(temp[i]);
            }
            cout << path.size() << " ";
            for (auto it : path)
                cout << it << " ";
            cout << "\n";
        }
    }

    return 0;
}