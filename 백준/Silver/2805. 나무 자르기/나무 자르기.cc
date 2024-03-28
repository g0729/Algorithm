#include<bits/stdc++.h>
using namespace std;
#define lint long long
#define MAX 1000000
int arr[MAX];
lint n,m;
int len;
lint res;
lint cal(lint mid)
{
    lint res=0;
    for(int i = 0 ; i<n;i++)
    {
        if(arr[i]>mid)
        {
            res+=arr[i]-mid;
        }
    }
    return res;
}
void binsearch()
{
    lint start=1;
    lint end=len+1;
    while(start<end)
    {
        lint mid=(start+end)/2;
        lint cnt=cal(mid);
        if(cnt<m)
        {
            end=mid;
        }
        else
        {
            res=max(res,mid);
            start=mid+1;
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i = 0 ; i<n;i++)
    {
        cin>>arr[i];
        len = max(len,arr[i]);
    }
    binsearch();
    cout<<res;
}