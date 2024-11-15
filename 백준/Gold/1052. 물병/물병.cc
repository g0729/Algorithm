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

    int n, k;
    cin >> n >> k;
    bitset<30> bits(n);
    int cur = 1;
    int res = 0;
    int idx = 0;
    while (bits.count() > k)
    {
        if (bits[idx] == 1)
        {
            n += cur;
            bits = n;
            res += cur;
        }
        cur *= 2;
        idx++;
    }

    cout << res;

    return 0;
}