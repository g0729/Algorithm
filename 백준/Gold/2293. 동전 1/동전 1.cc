#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
int n,m;
int dp[MAX];
int arr[100];
int main()
{
    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    dp[0]=1;
    for(int i =0;i<n;i++)
    {
        for(int q = arr[i];q<=m;q++)
        {
            dp[q] +=dp[q-arr[i]];
        }
    }
    cout<<dp[m];
}