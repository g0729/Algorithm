#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int flat(int x, int y)
{
    return x * 3 + y;
}
int bfs(int target)
{
    queue<int> q;
    q.push(0);
    vector<bool> visited(600);
    visited[0] = true;

    int res = 0;
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            int now = q.front();
            if (now == target)
                return res;
            q.pop();
            bitset<9> bits(now);

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    bitset<9> temp(bits);

                    temp[flat(i, j)] = (temp[flat(i, j)] + 1) % 2;
                    for (int k = 0; k < 4; k++)
                    {
                        int x = i + dx[k];
                        int y = j + dy[k];

                        if (x < 0 || x >= 3 || y < 0 || y >= 3)
                            continue;
                        temp[flat(x, y)] = (temp[flat(x, y)] + 1) % 2;
                    }

                    if (visited[temp.to_ulong()])
                        continue;
                    visited[temp.to_ulong()] = true;
                    q.push(temp.to_ulong());
                }
            }
        }
        res++;
    }
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
        bitset<9> bits;
        for (int i = 0; i < 3; i++)
        {
            string s;
            cin >> s;
            for (int j = 0; j < 3; j++)
            {
                if (s[j] == '*')
                    bits[flat(i, j)] = 1;
            }
        }
        cout << bfs(bits.to_ulong()) << "\n";
    }
    return 0;
}