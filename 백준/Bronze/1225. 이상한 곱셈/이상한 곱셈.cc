#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long res;

    string a,b;

    cin>>a>>b;

    int sumA,sumB;
    sumA=sumB=0;

    for (int i = 0; i < a.length(); i++)
    {
        sumA+=a[i]-'0';
    }
    
    for (int i = 0; i < b.length(); i++)
    {
        sumB+=b[i]-'0';
    }
    
    res=(long long)sumA*sumB;

    cout<<res;
}