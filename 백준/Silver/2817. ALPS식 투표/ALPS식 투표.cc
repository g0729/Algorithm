#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool cmp(pair<double, string> &a, pair<double, string> &b)
{
    return a.first > b.first;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x, n;
    cin >> x >> n;

    vector<pair<double, string>> v;
    map<string, int> ma;
    for (int i = 0; i < n; i++)
    {
        string s;
        int a;
        cin >> s >> a;
        if (a < (double)x * 0.05)
            continue;
        for (int j = 1; j <= 14; j++)
            v.push_back({(double)a / j, s});
        ma[s] = 0;
    }
    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < 14; i++)
        ma[v[i].second]++;

    vector<pair<string, int>> res;
    for (auto it : ma)
        res.push_back(it);
    sort(res.begin(), res.end());

    for (auto it : res)
        cout << it.first << " " << it.second << "\n";
    return 0;
}