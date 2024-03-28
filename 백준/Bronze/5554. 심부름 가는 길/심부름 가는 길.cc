#include <bits/stdc++.h>
using namespace std;

int main()
{
    int sum=0;
    for (int i = 0; i < 4; i++)
    {
        int a;
        cin>>a;
        sum+=a;
    }
    cout<<sum/60<<"\n"<<sum%60;
}