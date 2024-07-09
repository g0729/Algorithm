#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int n, m;
vector<pair<string, int>> v;

int bin_search(int &target)
{
    int left = -1, right = v.size();

    while (left + 1 < right)
    {
        int mid = (left + right) / 2;

        if (v[mid].second < target)
            left = mid;
        else
            right = mid;
    }

    return right;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int a;
        string s;
        cin >> s >> a;
        if (!v.empty() && v.back().second == a)
            continue;
        v.push_back({s, a});
    }

    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        int idx = bin_search(a);
        cout << v[idx].first << "\n";
    }

    return 0;
}