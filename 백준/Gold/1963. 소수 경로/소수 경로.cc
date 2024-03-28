#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

bool isPrime[10001];
bool visited[10001];
int from, to;
void eratos()
{
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= 10000; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= 10000; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}
int bfs()
{
    queue<int> q;
    q.push(from);
    visited[from] = true;

    int res = 0;
    while (!q.empty())
    {
        int size = q.size();

        while (size--)
        {
            int now = q.front();
            if (now == to)
                return res;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                string temp = to_string(now);
                for (int j = 0; j < 10; j++)
                {
                    if (i == 0 && j == 0)
                        continue;
                    temp[i] = j + '0';
                    int temp2 = stoi(temp);
                    if (visited[temp2])
                        continue;
                    if (!isPrime[temp2])
                        continue;
                    q.push(temp2);
                    visited[temp2] = true;
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
    memset(isPrime, 1, sizeof(isPrime));
    eratos();
    int t;
    cin >> t;
    while (t--)
    {
        cin >> from >> to;
        cout << bfs() << endl;
        memset(visited, 0, sizeof(visited));
    }
    return 0;
}