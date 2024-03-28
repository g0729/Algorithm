#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[1000];
    int dp[1000]={0};

    int n;
    cin>>n;

    for(int i = 0 ; i<n;i++)
    {
        cin>>arr[i];
    }
    dp[0]=arr[0];

    for(int i =1 ; i<n;i++)
    {
        dp[i]=arr[i];

        for(int j=0;j<i;j++)
        {
            if(arr[j]<arr[i])
            {
                dp[i]=max(dp[i],dp[j]+arr[i]);
            }
        }
    }

    int res=0;

    for(int i = 0 ; i<n;i++)
    {
        res=max(res,dp[i]);
    }
    cout<<res;
}