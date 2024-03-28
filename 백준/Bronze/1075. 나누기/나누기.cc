#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,f;
    cin>>n>>f;
    n=(n/100)*100;
    for (int i = 0; i < 100; i++)
    {
        if((n+i)%f==0)
        {
            if(n%100+i<10)
            {
                cout<<"0"<<n%100+i;
                break;
            }
            else
            {
                cout<<n%100+i;
                break;
            }
            
        }
    }
    
}