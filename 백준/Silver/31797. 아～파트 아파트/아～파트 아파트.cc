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

    int n, m;
    cin >> n >> m;
    n = (n - 1) % (2 * m) + 1;
    vector<pair<int, int>> v;
    vector<int> heights;
    map<int, int> order;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
        heights.push_back(a);
        heights.push_back(b);
    }

    sort(heights.begin(), heights.end());

    for (int i = 0; i < heights.size(); i++)
    {
        order[heights[i]] = i + 1;
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        a = order[v[i].first];
        b = order[v[i].second];
        if (a == n || b == n)
        {
            cout << i + 1;
            break;
        }
    }

    return 0;
}