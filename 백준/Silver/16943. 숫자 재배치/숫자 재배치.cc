#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

vector<int> v;
bool sel[9];
int b;
int res;
void dfs(int now, int sum)
{

    if (now == v.size())
    {
        if (sum < b)
            res = max(res, sum);

        return;
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (sel[i])
            continue;

        if (now == 0 && v[i] == 0)
            continue;

        sel[i] = true;
        dfs(now + 1, sum * 10 + v[i]);
        sel[i] = false;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s >> b;

    for (int i = 0; i < s.length(); i++)
    {
        v.push_back(s[i] - '0');
    }

    dfs(0, 0);

    if (res == 0)
        cout << "-1";
    else
        cout << res;
    return 0;
}