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
    vector<int> v(11, -1);
    int n;
    cin >> n;
    int res = 0;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        if (v[a] == -1)
            v[a] = b;
        else
        {
            if (v[a] != b)
                res++;
            v[a] = b;
        }
    }

    cout << res;
    return 0;
}