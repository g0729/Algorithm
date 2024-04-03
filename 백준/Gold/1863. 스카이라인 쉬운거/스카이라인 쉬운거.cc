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
    stack<int> s;
    int n;
    cin >> n;
    int res = 0;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        if (s.empty())
            s.push(b);
        else
        {
            while (!s.empty() && s.top() > b)
            {
                res++;
                s.pop();
            }
            if (s.empty())
                s.push(b);
            else if (s.top() != b)
                s.push(b);
        }
    }
    while (!s.empty() && s.top() != 0)
    {
        res++;
        s.pop();
    }
    cout << res;
    return 0;
}