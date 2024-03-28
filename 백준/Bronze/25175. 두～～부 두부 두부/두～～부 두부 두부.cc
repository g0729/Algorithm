#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,k;

    cin>>n>>m>>k;

    k=k-3;

    m+=k;

    m%=n;

    if(m<=0)
    m+=n;

    cout<<m;
}