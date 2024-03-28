#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321

bool cmp(pair<string, int> &a, pair<string, int> &b)
{
    if (a.first[0] == b.first[0])
    {
        return stoi(a.first.substr(2)) < stoi(b.first.substr(2));
    }
    return a.first[0] < b.first[0];
}

bool cmp2(pair<string, int> &a, pair<string, int> &b)
{
    return a.second < b.second;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<pair<string, int>> v;
    for (int i = 0; i < n; i++)
    {
        string s;
        for (int j = 0; j < 5; j++)
        {
            cin >> s;
            v.push_back({s, i * 5 + j});
        }
    }
    vector<int> y(n * 5);

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < v.size(); i++)
    {
        y[v[i].second] = i;
    }

    sort(v.begin(), v.end(), cmp2);

    for (int i = 0; i < v.size(); i++)
    {
        v[i].second = y[v[i].second];
    }

    stack<int> s;
    int idx = 0;

    for (int i = 0; i < v.size(); i++)
    {
        int now = v[i].second;

        if (idx == now)
            idx++;
        else
        {
            s.push(now);
        }

        while (!s.empty() && s.top() == idx)
        {
            s.pop();
            idx++;
        }
    }

    if (s.empty())
        cout << "GOOD";
    else
        cout << "BAD";
    return 0;
}