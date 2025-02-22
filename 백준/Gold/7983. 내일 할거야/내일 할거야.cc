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
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;

    sort(v.begin(), v.end(), [](pair<int, int> &a, pair<int, int> &b) -> bool
         { return a.second > b.second; });

    int end = v[0].second - v[0].first;

    for (int i = 1; i < n; i++)
    {
        if (v[i].second <= end)
            end = v[i].second - v[i].first;
        else
            end = end - v[i].first;
    }

    cout << end;

    return 0;
}