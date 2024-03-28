#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int>v;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    
    sort(v.begin(),v.end());

    int res=1;

    int now=0;

    while(1)
    {
        if(res==v[now])
        {
            res++;
            now++;
        }
        else
        break;
    }

    cout<<res;
}