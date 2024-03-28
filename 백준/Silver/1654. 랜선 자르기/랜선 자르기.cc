#include<bits/stdc++.h>
using namespace std;
#define lint long long
#define MAX 10000
int n,k;
lint arr[MAX];
lint res;
lint len;
int cnt(int dis)
{
    int res=0;
    for(int i = 0 ; i<k;i++)
    {
        res+=arr[i]/dis;
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
        int count = cnt(mid);
        if(count<n)
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
    cin>>k>>n;
    for(int i = 0 ; i<k;i++)
    {
        cin>>arr[i];
        len=max(len,arr[i]);
    }
    binsearch();
    cout<<res;
}

