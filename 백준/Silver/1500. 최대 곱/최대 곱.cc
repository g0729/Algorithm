#include <bits/stdc++.h>
using namespace std;

int main()
{
    int s,k;
    cin>>s>>k;
    int a=s/k;
    int b=s%k;
    long long res=1;
    for (int i = 0; i < b; i++)
    {
        res*=(a+1);
    }
    
    for (int i = 0; i < k-b; i++)
    {
        res*=a;
    }
    cout<<res;
}