#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(2 * n);

    for (int i = 0; i < 2 * n; i++)
        cin >> a[i];

    queue<int> robots;
    vector<bool> visited(2 * n);
    int start = 0, zero_count = 0, step = 0, level = 1, end = n - 1;
    while (true)
    {
        if (step == 0)
        {
            start = (start - 1 + 2 * n) % (2 * n);
            end = (start + n - 1) % (2 * n);
        }
        else if (step == 1)
        {
            int size = robots.size();
            for (int i = 0; i < size; i++)
            {
                int cur = robots.front();
                visited[cur] = false;
                robots.pop();
                if (cur == end)
                    continue;

                int next = (cur + 1) % (2 * n);

                if (a[next] >= 1 && !visited[next])
                {
                    a[next]--;
                    if (a[next] == 0)
                        zero_count++;
                    if (next == end)
                        continue;
                    visited[next] = true;
                    robots.push(next);
                }
                else
                {
                    visited[cur] = true;
                    robots.push(cur);
                }
            }
        }
        else if (step == 2)
        {
            if (a[start] != 0)
            {
                a[start]--;
                if (a[start] == 0)
                    zero_count++;
                robots.push(start);
                visited[start] = true;
            }
        }
        else if (step == 3)
        {
            if (zero_count >= k)
                break;
            level++;
        }
        step = (step + 1) % 4;
    }

    cout << level;
    return 0;
}