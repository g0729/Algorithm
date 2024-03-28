#include <bits/stdc++.h>
using namespace std;

vector<int>v;
long long n;
long long res;
    int k;

void dfs(long long now)
{
    if(now>n)
    return;
    res=max(res,now);
    for(int i = 0 ; i<k;i++)
    {
        dfs(now*10+v[i]);
    }
}
int main()
{
    cin>>n;
    cin>>k;

    for (int i = 0; i < k; i++)
    {
        int a;
        cin>>a;

        v.push_back(a);
    }
    dfs(0);
    cout<<res;   
}