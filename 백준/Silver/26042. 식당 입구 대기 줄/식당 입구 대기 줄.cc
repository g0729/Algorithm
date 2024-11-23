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
    queue<int> q;
    int res = 0;
    int idx;
    while (n--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int a;
            cin >> a;
            q.push(a);
        }
        else
        {
            q.pop();
        }
        if (q.size() > res)
        {
            res = q.size();
            idx = q.back();
        }
        else if (q.size() == res && idx > q.back())
        {
            idx = q.back();
        }
    }
    cout << res << " " << idx;
    return 0;
}