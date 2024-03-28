#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int arr[100000];
    long long sum[100000]={0,};
    int n;

    cin>>n;
    cin>>arr[0];
    sum[0]=arr[0];

    for (int i = 1; i < n; i++)
    {
        int a;

        cin>>a;
        arr[i]=a;
        sum[i]=sum[i-1]+a;
    }
    
    long long res=0;

    for (int i = 0; i < n-1 ; i++)
    {
        res+=arr[i]*(sum[n-1]-sum[i]);
    }
   
    cout<<res;

}