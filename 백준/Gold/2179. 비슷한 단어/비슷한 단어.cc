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
    map<string, int> ma;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    pair<string, string> res;
    pair<int, int> res_idx;
    int max_length = 0;
    for (int i = 0; i < n; i++)
    {
        string now = v[i];
        for (int j = 1; j < now.length() + 1; j++)
        {
            string prefix = now.substr(0, j);
            if (ma.find(prefix) == ma.end())
                ma.insert({prefix, i});
            else
            {
                if (v[ma[prefix]] == v[i])
                    continue;
                if (max_length < prefix.length())
                {
                    max_length = prefix.length();
                    res = {v[ma[prefix]], v[i]};
                    res_idx = {ma[prefix], i};
                }
                else if (max_length == prefix.length())
                {
                    if (ma[prefix] < res_idx.first)
                    {
                        res = {v[ma[prefix]], v[i]};
                        res_idx = {ma[prefix], i};
                    }
                }
            }
        }
    }
    cout << res.first << "\n"
         << res.second;
    return 0;
}