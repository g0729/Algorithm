#include<bits/stdc++.h>
using namespace std;
int check[100001];
int arr[200000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int start=0;
    int end=0;
    int res=0;
    int cnt=0;

    while(end<n)
    {
        check[arr[end]]++;
        if(check[arr[end]]>k)
        {
            while(check[arr[end]]>k)
            {
                check[arr[start]]--;
                start++;
                cnt--;
            }
        }
        end++;
        cnt++;
        res=max(res,cnt);
    }
    cout<<res;
}