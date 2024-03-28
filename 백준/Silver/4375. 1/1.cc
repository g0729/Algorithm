#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        int cnt=1;
        int now=1;
        while(1)
        {
            if(now%n==0)
            {
                cout<<cnt<<"\n";
                break;
            }
            now=((now*10)+1)%n;
            cnt++;
        }
    }
}