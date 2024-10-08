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
    map<int, int> ma;

    for (int i = 0; i < n; i++)
    {
        int s;
        cin >> s;
        ma[s]++;
    }

    vector<int> v;

    for (auto it : ma)
    {
        v.push_back(it.first);
        if (it.second >= 2)
            v.push_back(it.first);
    }

    sort(v.begin(), v.end());

    vector<int> res;
    int len = min(4, n);
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (i != j)
            {
                res.push_back(stoi(to_string(v[i]) + to_string(v[j])));
            }
        }
    }

    sort(res.begin(), res.end());

    cout << res[2];

    return 0;
}