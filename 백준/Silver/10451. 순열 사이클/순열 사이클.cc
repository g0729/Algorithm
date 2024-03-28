#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<bool> check(n + 1);
        vector<int> v(n + 1);

        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
        }

        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!check[i])
            {
                int now = i;
                int next = v[i];
                while (1)
                {
                    if (check[now])
                        break;
                    check[now] = true;
                    now = next;
                    next = v[now];
                }
                res++;
            }
        }
        cout<<res<<"\n";
    }

    return 0;
}