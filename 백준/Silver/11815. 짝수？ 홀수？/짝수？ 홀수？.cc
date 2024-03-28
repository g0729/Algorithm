#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        long long a;
        cin>>a;
        long long temp=sqrt(a);

        if(temp*temp==a)
        cout<<"1 ";
        else
        cout<<"0 ";
    }
}