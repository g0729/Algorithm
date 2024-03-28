#include <bits/stdc++.h>
using namespace std;
int n,k;
vector<int>v;
bool check(int target)
{
    int min,max;
    min=10000;
    max=0;
    int cnt=1;
    for (int i = 0; i < n; i++)
    {
        if(min>v[i])
        min=v[i];
        if(max<v[i])
        max=v[i];
        if(max-min>target)
        {
            cnt++;
            max=v[i];
            min=v[i];
        }
    }
    if(cnt>k)
    return false;
    else
    return true;
}
int binseach()
{
    int start=0;
    int end=10001;
    while(start<end)
    {
        int mid=(start+end)/2;
        bool temp=check(mid);
        if(temp)
            end=mid;
        else
            start=mid+1;
    }
    return end;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    int res=binseach();
    cout<<res;   
}