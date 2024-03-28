#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define INF 987654321
vector<int> v;
int sp[5000001];

void linear_sieve(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!sp[i])
            v.push_back(i);
        for (auto j : v)
        {
            if (i * j > n)
                break;
            sp[i * j] = j;
            if (i % j == 0)
                break;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    vector<int> v2(t);

    int MAX = 0;
    for (int i = 0; i < t; i++)
    {
        cin >> v2[i];
        MAX = max(MAX, v2[i]);
    }
    linear_sieve(MAX);

    for (int i = 0; i < t; i++)
    {
        int n = v2[i];
        while (sp[n])
        {
            cout << sp[n] << " ";
            n /= sp[n];
        }
        cout << n << "\n";
    }
    return 0;
}