#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321

int parse(string &s)
{
    string hour, minute, second, millisecond;
    hour = s.substr(0, 2);
    minute = s.substr(3, 2);
    second = s.substr(6, 2);
    millisecond = s.substr(9);
    int total = stoi(hour) * 1000 * 60 * 60 + stoi(minute) * 1000 * 60 + stoi(second) * 1000 + stoi(millisecond);

    return total;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<pair<string, string>> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;

    sort(v.begin(), v.end());

    priority_queue<int, vector<int>, greater<int>> pq;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int time_in = parse(v[i].first), time_out = parse(v[i].second);

        while (!pq.empty() && pq.top() <= time_in)
            pq.pop();
        pq.push(time_out);
        res = max(res, (int)pq.size());
    }

    cout << res;

    return 0;
}