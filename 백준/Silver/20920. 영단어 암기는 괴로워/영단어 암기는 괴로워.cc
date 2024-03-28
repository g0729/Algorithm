#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

map<string, int> ma;
bool cmp(string a, string b)
{
    if (ma[a] == ma[b])
    {
        if (a.length() == b.length())
            return a<b;
        
        return a.length()>b.length();
    }

    return ma[a]>ma[b];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        if (s.length() < m)
            continue;

        ma[s]++;
    }

    vector<string> v;

    for (auto it : ma)
    {
        v.push_back(it.first);
    }

    sort(v.begin(), v.end(), cmp);

    for (auto it : v)
        cout << it << "\n";

    return 0;
}