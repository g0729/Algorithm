#include<bits/stdc++.h>
using namespace std;
#define lint unsigned long long  
bool check(lint n)
{
    if(n<=1)
    return false;
    for (lint i = 2; i *i<= n; i++)
    {
        if(n%i==0)
        return false;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    while(n--)
    {
        lint a;
        cin>>a;
        for (lint i = a;; i++)
        {
            if(check(i))
            {
                cout<<i<<"\n";
                break;
            }
        }
    }
}