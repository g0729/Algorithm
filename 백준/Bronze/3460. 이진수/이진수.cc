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
    int t;
    cin >> t;
    while (t--)
    {
        int n, idx = 0;
        cin >> n;

        while (n)
        {
            if (n & 1)
                cout << idx << " ";
            n >>= 1;
            idx++;
        }

        cout << "\n";
    }
    return 0;
}