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

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n + 1);

        for (int i = 1; i <= n; i++)
        {
            for (int j = i; j <= n; j += i)
            {
                v[j]++;
            }
        }

        int res=0;

        for(int i = 1;i<=n;i++)
        {
            if(v[i]%2==1)
                res++;
        }

        cout<<res<<"\n";
    }
    return 0;
}