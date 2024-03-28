#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>v;
    vector<int>dp;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin>>a;
            v.push_back(a);
        }
        dp.push_back(v[0]);
        for (int i = 1; i < v.size(); i++)
        {
            if(dp.back()<v[i])
            {
                dp.push_back(v[i]);
                continue;
            }
            auto temp=lower_bound(dp.begin(),dp.end(),v[i]);
            *temp= v[i];
        }
        cout<<dp.size()<<"\n";
        dp.clear();
        v.clear();
    }
}