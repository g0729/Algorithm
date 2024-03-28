#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long x,y,z;

    cin>>x>>y;
    z=(double)(y*100/x);

    if(z==100||z==99)
    {
        cout<<"-1";
        return 0;
    }

    long long start,end;
    start=0;
    end=x;


    while(start+1<end)
    {
        long long mid=(start+end)/2;
        long long temp=(double)((y+mid)*100)/(x+mid);

        if(temp==z)
        {
            start=mid;
        }
        else
        {
            end=mid;
        }
    }
    
    cout<<end;
}