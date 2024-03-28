#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000
int cnt[MAX+1];
int arr[MAX+1];
int res[MAX+1];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        cnt[arr[i]]++;
    }
    stack<pair<int,int>>v;
    for(int i =n;i>0;i--)
    {
        while(!v.empty()&&v.top().second<=cnt[arr[i]])
        {
            v.pop();
        }
        if(v.empty())
        {
            res[i]=-1;
        }
        else
        {
            res[i]=v.top().first;
        }
        v.push({arr[i],cnt[arr[i]]});
    }
    for(int i =1 ; i<=n;i++)
    {
        cout<<res[i]<<" ";
    }
}