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
    priority_queue<int, vector<int>, greater<int>> pq;
    int n;
    cin >> n;

    vector<pair<int, int>> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;

    sort(v.begin(), v.end(), [](pair<int, int> &a, pair<int, int> &b)
         { return a.first < b.first; });

    int res = 0;

    for (int i = 0; i < n; i++)
    {
        if (pq.empty())
            pq.push(v[i].second);
        else
        {
            if (v[i].first >= pq.top())
            {
                pq.pop();
                pq.push(v[i].second);
            }
            else
            {
                pq.push(v[i].second);
            }
            res = max(res, (int)pq.size());
        }
    }

    cout << res;

    return 0;
}