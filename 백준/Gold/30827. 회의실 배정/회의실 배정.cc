#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    int res = 0;
    sort(v.begin(), v.end(), cmp);
    vector<int> rooms(k, -1);

    for (int i = 0; i < n; i++)
    {

        sort(rooms.begin(), rooms.end());
        for (int j = k - 1; j >= 0; j--)
        {
            if (rooms[j] < v[i].first)
            {
                rooms[j] = v[i].second;
                res++;
                break;
            }
        }
    }

    cout << res;
    return 0;
}