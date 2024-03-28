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

    int n;
    cin >> n;

    vector<int> v;

    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        v.insert(v.begin() + (i - a - 1), i);
    }

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}