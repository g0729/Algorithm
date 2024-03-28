#include<bits/stdc++.h>
using namespace std;
#define lint long long
lint a,b;
lint total_use;
lint ans;
lint use(lint cost)
{
    if(cost>4979900)
    return ((cost-4979900)/7)+1000000;
    else if(cost>29900)
    return ((cost-29900)/5)+10000;
    else if(cost>200)
    return ((cost-200)/3)+100;
    else
        return cost/2;
}
lint cost(lint use)
{
    if(use>1000000)
        return (use-1000000)*7+4979900;
    else if(use>10000)
        return (use-10000)*5+29900;
    else if(use>100)
        return (use-100)*3+200;
    else
        return use*2;
        
}
void binsearch()
{
    lint start=1;
    lint end=total_use/2+1;
    while(start<=end)
    {
        lint mid=(start+end)/2;
        if(cost(total_use-mid)-cost(mid)==b)
        {   ans=cost(mid);
            break;
        }
        else if(cost(total_use-mid)-cost(mid)<b)
        {
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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(1)
    {
        cin>>a>>b;
        if(a==0&&b==0)
        {
            return 0;
        }
        total_use=use(a);
        binsearch();
        cout<<ans<<"\n";
    }
}