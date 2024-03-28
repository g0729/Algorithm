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
    cin >> n;

    vector<int> v(n);
    vector<bool> check(1000001);
    vector<int> ans(1000001);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        check[v[i]] = true;
    }

    for (int i = 0; i < n; i++)
    {
        int now = v[i];
        for (int j = 1; j * j <= now; j++)
        {
            if (now % j == 0)
            {
                if(check[j])
                {
                    ans[now]-=1;
                    ans[j]+=1;
                }
                if(j*j!=now&&check[now/j])
                {
                    ans[now]-=1;
                    ans[now/j]+=1;
                }

            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout<<ans[v[i]]<<" ";
    }
    
    return 0;
}