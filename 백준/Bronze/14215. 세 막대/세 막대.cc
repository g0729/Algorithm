#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> v(3);

    for (int i = 0; i < 3; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    if (v[2] >= v[1] + v[0])
    {
        cout << (v[1] + v[0]) * 2 - 1;
    }
    else
    {
        cout << (v[0] + v[1] + v[2]);
    }
    return 0;
}