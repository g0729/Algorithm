#include <bits/stdc++.h>
using namespace std;

#define lint long long
int main()
{
    lint a=0,r;
    lint n;
    cin>>n;
  
    
    for ( r = 2; r*r < n; r++)
    {
        lint sum=1+r+r*r;

        lint temp=r*r*r;
        lint cnt=3;
        while(1)
        {
            if(sum>n)
            break;
            if(n%sum==0)
            {
                a=n/sum;
                cout<<cnt<<"\n";
                for (int i = 0; i < cnt; i++)
                {
                    cout<<a<<" ";
                    a*=r;
                }
                return 0;
                
            }
            sum+=temp;
            temp*=r;
            cnt++;
        }    
    }
    if(a==0)
    {
        cout<<"-1";
        return 0;
    }   

}