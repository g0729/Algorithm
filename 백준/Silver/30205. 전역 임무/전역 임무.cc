#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, m, p;
    cin >> n >> m >> p;
    for (int i = 0; i < n; i++)
    {
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        int item_cnt = 0;
        for (int j = 0; j < m; j++)
        {
            int a;
            cin >> a;

            if (a == -1)
                item_cnt++;
            else
                pq.push(a);
        }

        while (!pq.empty())
        {
            if (pq.top() <= p)
            {
                p += pq.top();
                pq.pop();
            }
            else
            {
                if (item_cnt)
                {
                    p *= 2;
                    item_cnt--;
                }
                else
                {
                    cout << "0";
                    return 0;
                }
            }
        }
        while (item_cnt)
        {
            p *= 2;
            item_cnt--;
        }
    }

    cout << "1";
    return 0;
}