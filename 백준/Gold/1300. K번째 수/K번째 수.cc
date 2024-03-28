#include<bits/stdc++.h>
using namespace std;
int n;
int k;
int res;
int check(int target)
{
    int res=0;
    for (int i=1 ; i <= n; i++)
    {
       res+=min(target/i,n);
    }
    return res;
}
void binsearch()
{
    int start=1;
    int end=k;
    while(start<=end)
    {
        int mid=(start+end)/2;
        int temp=check(mid);
        if(temp>=k)
        {
            res=mid;
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
}
int main()
{
    cin>>n>>k;
    binsearch();
    cout<<res;
}