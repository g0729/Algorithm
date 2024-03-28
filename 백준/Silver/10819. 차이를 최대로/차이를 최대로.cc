#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long
bool sel[8];
vector<int> v;
int n;
int res;
void dfs(int now, int before, int sum)
{
    if (now == n)
    {
        res=max(res,sum);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (sel[i])
            continue;
        
        sel[i]=true;
        dfs(now+1,v[i],sum+abs(v[i]-before));
        sel[i]=false;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
        sel[i]=true;
        dfs(1,v[i],0);
        sel[i]=false;
    }
    
    cout<<res;
    return 0;
}