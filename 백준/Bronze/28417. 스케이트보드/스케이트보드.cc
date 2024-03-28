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


    int n;
    cin>>n;

    int res=0;
    for (int i = 0; i < n; i++)
    {
        vector<int>v(2);
        vector<int>v2(5);

        for (int j = 0; j < 2; j++)
        {
            cin>>v[j];
        }
        for (int j = 0; j < 5; j++)
        {
            cin>>v2[j];
        }
        sort(v.begin(),v.end());
        sort(v2.begin(),v2.end());

        res=max(res,v[1]+v2[3]+v2[4]);

    }
    cout<<res;
    return 0;
}