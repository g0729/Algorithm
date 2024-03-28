#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b;
    cin >> a >> b;
    int res = 0;
    a--;
    b--;
    res += abs(a % 4 - b % 4);

    res+=abs(b/4-a/4);

    cout<<res;
    return 0;
}