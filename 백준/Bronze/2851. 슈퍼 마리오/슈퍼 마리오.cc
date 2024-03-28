#include <bits/stdc++.h>
using namespace std;

int main()
{
    int sum=0;
    int res=0;

    for (int i = 0; i < 10; i++)
    {
        int a;
        cin>>a;

        sum+=a;

        if(abs(res-100)>=abs(sum-100))
        {
            res=sum;
        }
    }
    
    cout<<res;
}