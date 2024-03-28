#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000000
#define lint long long
lint m;
lint ans=MAX;
lint cnt(lint target)
{
    lint res=0;
    lint div=5;
    while(target/div>0)
    {
        res+=target/div;
        div*=5;
    }
    return res;
}
void binsearch()
{
    lint start=1;
    lint end=MAX;
    lint check;
    while(start<=end)
    {
        lint mid=(start+end)/2;
        check=cnt(mid);
        if(check>=m)
        {
            if(check==m)
            {
                ans=min(ans,mid);
            }
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
    cin>>m;
    binsearch();
    if(ans==MAX)
    cout<<"-1";
    else
    cout<<ans;
}
