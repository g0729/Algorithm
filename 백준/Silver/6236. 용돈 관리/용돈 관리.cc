#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[100000];
int res=1000000000;
int check(int target)
{
    int cnt=1;
    int temp=target;
    for (int i = 0; i < n; i++)
    {
        if(target<arr[i])
        return -1;
        temp-=arr[i];
        if(temp<0)
        {
            temp=target;
            temp-=arr[i];
            cnt++;
        }
    }
    return cnt;
}
void binsearch()
{
    int start=1;
    int end=1000000000;
    while(start<=end)
    {
        int mid =(start+end)/2;
        int temp=check(mid);
        if(temp==-1)
        {
            start=mid+1;
        }
        else if(temp>m)
        {
            start=mid+1;
        }
        else if(temp<=m)
        {
            res=min(res,mid);
            end=mid-1;
        }
    }
}
int main()
{
    cin >> n>>m;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    binsearch();
    cout<<res;
}