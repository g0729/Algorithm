#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;

    cin>>n>>k;

    int low_cnt=1;
    int high_cnt=n;

    for(int i =1 ; i<=n;i++)
    {
        if(n-i<=k)
        {
            cout<<high_cnt<<" ";
            high_cnt--;
            k-=n-i;
        }
        else
        {
            cout<<low_cnt<<" ";
            low_cnt++;
        }
    }
}