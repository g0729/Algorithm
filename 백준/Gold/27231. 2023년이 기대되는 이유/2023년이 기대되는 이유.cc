#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
set<int> se;
string s;
int n;
void dfs(int now, int num, int temp)
{
    if (now == n)
    {
        num += temp;
        se.insert(num);
        return;
    }
    dfs(now + 1, num + temp * 10 + s[now] - '0', 0);
    dfs(now + 1, num, temp * 10 + s[now] - '0');
}
int pow(int a, int b)
{
    int res = 1;
    for (int i = 1; i <= b; i++)
    {
        res *= a;
    }
    return res;
}
int cal(int m)
{
    int res = 0;
    for (int i = 0; i < s.length(); i++)
    {
        res += pow(s[i] - '0', m);
    }

    return res;
}
bool check()
{
    int cnt[10] = {
        0,
    };
    for (int i = 0; i < s.length(); i++)
    {
        cnt[s[i] - '0']++;
    }

    for (int i = 2; i < 10; i++)
    {
        if (cnt[i])
            return false;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> s;
        n = s.length();

        if (check())
        {
            cout << "Hello, BOJ 2023!\n";
            continue;
        }
        dfs(0, 0, 0);

        int Max = stoi(s);
        int m = 1;
        int res = 0;
        while (1)
        {
            int temp = cal(m);
            if (se.find(temp) != se.end())
                res++;
            if (temp > Max)
                break;
            m++;
        }
        cout << res << "\n";
        se.clear();
    }
    return 0;
}