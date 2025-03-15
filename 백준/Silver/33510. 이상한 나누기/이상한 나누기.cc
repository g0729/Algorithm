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
    string s;
    cin >> s;
    int res = 0;
    for (int i = s.length() - 1; i >= 1; i--)
    {
        if (res)
        {
            if (s[i] == '0')
                res++;
        }
        else
        {
            if (s[i] == '1')
                res++;
        }
    }

    cout << res;

    return 0;
}