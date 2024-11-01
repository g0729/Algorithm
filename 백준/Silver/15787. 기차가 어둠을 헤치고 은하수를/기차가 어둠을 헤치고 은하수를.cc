#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
vector<bool> visited(1e7);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<bitset<20>> v(n, bitset<20>(0));

    for (int i = 0; i < m; i++)
    {
        int op, num, a;
        cin >> op >> num;
        num -= 1;
        if (op == 1)
        {
            cin >> a;
            v[num][a - 1] = 1;
        }
        else if (op == 2)
        {
            cin >> a;
            v[num][a - 1] = 0;
        }
        else if (op == 3)
        {
            v[num] <<= 1;
        }
        else
        {
            v[num] >>= 1;
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        unsigned long a = v[i].to_ulong();
        if (visited[a])
            continue;
        visited[a] = true;
        res++;
    }

    cout << res;
    return 0;
}