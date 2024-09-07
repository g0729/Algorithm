#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
string rsp = "RSP";
int n, m, k;
vector<string> v;
string res;
int bfs()
{
    queue<pair<vector<int>, string>> q;
    for (int i = 0; i < 3; i++)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
            temp.push_back(j);
        q.push({temp, ""});
    }

    int level = 0;
    while (!q.empty())
    {
        int size = q.size();

        while (size--)
        {
            vector<int> now = q.front().first;
            string cur = q.front().second;
            q.pop();

            if (now.size() <= k)
            {
                res = cur;
                return level;
            }
            for (int i = 0; i < 3; i++)
            {
                vector<int> temp;

                for (int j = 0; j < now.size(); j++)
                {
                    if (i == 0 && v[now[j]][level] == 'P')
                        temp.push_back(now[j]);
                    else if (i == 1 && v[now[j]][level] == 'R')
                        temp.push_back(now[j]);
                    else if (i == 2 && v[now[j]][level] == 'S')
                        temp.push_back(now[j]);
                }
                if (!temp.empty())
                    q.push({temp, cur + rsp[i]});
            }
        }
        level++;
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }
    cout << bfs() << "\n"
         << res;
    return 0;
}