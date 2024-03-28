#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        int count=0;
        for (int j =1; j <= 10; j++)
        {
            int temp;
            cin>>temp;
            if((j-1)%5+1==temp)
            count++;
        }
        if(count==10)
        cout<<i<<"\n";
    }
    
}