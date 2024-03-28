#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,n;

    cin>>a>>b>>n;

    a%=b;

    int now;
    for(int i= 0 ; i<n-1;i++)
    {
        a*=10;
        if(a<b)
            continue;
        else
            a%=b;
    }
    a*=10;
    now=a/b;
    cout<<now;
}