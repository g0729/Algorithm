#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

bool cmp(pair<string, string> a, pair<string, string> b)
{
    if (a.first == b.first)
        return a.second > b.second;

    return a.first < b.first;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<pair<string, string>> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end(),cmp);

    for (int i = 0; i < n; i++)
    {
        cout << v[i].first << " " << v[i].second << "\n";
    }

    return 0;
}