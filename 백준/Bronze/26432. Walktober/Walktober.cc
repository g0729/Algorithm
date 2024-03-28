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
    for(int k=1;k<=t;k++)
    {
        int n, m, p;

        cin >> m >> n >> p;

        vector<vector<int>> v((m), vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> v[i][j];
            }
        }

        int res = 0;

        for (int i = 0; i < n; i++)
        {
            int temp=0;
            for (int j = 0; j < m; j++)
            {
                temp=max(temp,v[j][i]);
            }
            res+=temp-v[p-1][i];
        }

        cout<<"Case #"<<k<<": "<<res<<"\n";
    }
    return 0;
}