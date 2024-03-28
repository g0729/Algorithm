#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int>v1,pair<int,int>v2)
{
    if(v1.first==v2.first)
    {
        return v1.second<v2.second;
    }
    else
    return v1.first>v2.first;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    multiset<int>ms;
    vector<pair<int,int>>v;

    for (int  i = 0; i < n; i++)
    {
        int a,b;
        cin>>a>>b;
        v.push_back({b,a});
    }
    sort(v.begin(),v.end(),cmp);
    for (int i = 0; i < k; i++)
    {
        int a;
        cin>>a;
        ms.insert(a);
    }

    
    long long res=0;
    for (int i = 0; i < n; i++)
    {
        int val=v[i].first;
        int wei=v[i].second;
        auto it=ms.lower_bound(wei);
        if(it!=ms.end())
        {
            res+=val;
            ms.erase(it);
        }
    }
    cout<<res;
    
}