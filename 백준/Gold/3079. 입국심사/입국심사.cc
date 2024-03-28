#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
#define lint long long 
int n,m;
lint arr[MAX];
lint res;

lint cnt(lint target)
{
    lint temp=0;
    for(int i = 0 ; i<n;i++)
    {
        temp+=target/arr[i];
        if(temp>1e18)
            break;
    }
    return temp;
}
void binsearch()
{
    lint start=1;
    lint end=1e18;
    res=end;
    while(start<=end)
    {
        lint mid=(start+end)/2;
        lint temp=cnt(mid);
        if(temp>=m)
        {
            res=min(res,mid);
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
    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    binsearch();
    cout<<res;
}