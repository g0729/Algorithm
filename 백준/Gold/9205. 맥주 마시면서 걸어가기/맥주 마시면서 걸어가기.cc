#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
pair<int, int> src;
pair<int, int> dst;
vector<pair<int, int>> v;
int n;
bool visited[110];
bool bfs()
{
    queue<pair<int, int>> q;
    visited[0] = true;
    q.push(src);

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == dst.first && y == dst.second)
            return true;
        for (int i = 0; i < v.size(); i++)
        {
            if (visited[i])
                continue;

            int diff = abs(x - v[i].first) + abs(y - v[i].second);

            if (diff > 1000)
                continue;

            q.push(v[i]);
            visited[i] = true;
        }
    }

    return false;
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
        cin >> n;
        cin >> src.first >> src.second;
        v.push_back(src);
        for (int i = 0; i < n; i++)
        {
            pair<int, int> temp;
            cin >> temp.first >> temp.second;
            v.push_back(temp);
        }
        cin >> dst.first >> dst.second;
        v.push_back(dst);

        if (bfs())
            cout << "happy";
        else
            cout << "sad";
        cout << "\n";
        v.clear();
        memset(visited, false, sizeof(visited));
    }
    return 0;
}