#include <bits/stdc++.h>
using namespace std;

int main()
{
    int res=0;
    int now=0;
    for (int i = 0; i < 4; i++)
    {
        int a,b;
        cin>>a>>b;
        now-=a;
        now+=b;
        res=max(res,now);
    }
    cout<<res;
}