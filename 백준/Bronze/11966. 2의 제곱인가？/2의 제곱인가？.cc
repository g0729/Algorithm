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
    int n;
    cin >> n;
    int cnt = 0;
    while (n)
    {
        cnt += n & 1;
        n >>= 1;
    }

    if (cnt == 1)
        cout << "1";
    else
        cout << "0";
    return 0;
}