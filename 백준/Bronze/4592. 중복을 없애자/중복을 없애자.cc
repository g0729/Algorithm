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
    while (1)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];

        cout << v[0] << " ";
        for (int i = 1; i < n; i++)
        {
            if (v[i] == v[i - 1])
                continue;
            cout << v[i] << " ";
        }
        cout << "$\n";
    }
    return 0;
}