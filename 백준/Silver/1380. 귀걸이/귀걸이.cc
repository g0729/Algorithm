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
    int t = 1;

    while (1)
    {
        int n;
        cin >> n;

        if (n == 0)
            break;

        cin.ignore();
        
        vector<string> v(n + 1);

        for (int i = 1; i <= n; i++)
            getline(cin,v[i]);

        vector<int> check(n + 1);

        for (int i = 0; i < 2 * n - 1; i++)
        {
            int a;
            char b;
            cin >> a >> b;
            check[a]++;
        }

        for (int i = 1; i <= n; i++)
        {
            if (check[i] == 1)
            {
                cout << t << " " << v[i] << "\n";
            }
        }
        t++;
    }
    return 0;
}