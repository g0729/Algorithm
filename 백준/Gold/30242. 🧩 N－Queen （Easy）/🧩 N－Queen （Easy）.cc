#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n;
vector<int> v;

void f(int idx)
{
    if (idx == n)
    {
        for (int i = 0; i < n; i++)
            cout << v[i] << " ";

        exit(0);
    }
    if (v[idx])
        f(idx + 1);
    else
    {
        for (int i = 1; i <= n; i++)
        {
            bool flag = true;
            for (int j = 0; j < n; j++)
            {
                if (v[j] == 0)
                    continue;
                if (v[j] == i || abs(idx - j) == abs(v[j] - i))
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                v[idx] = i;
                f(idx + 1);
                v[idx] = 0;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }

    f(0);

    cout << "-1";
    return 0;
}