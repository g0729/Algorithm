#include<bits/stdc++.h>
using namespace std;
#define MAX 500000
int arr[MAX];
int fin[MAX];
int res[MAX];
int n;

int upper(int target)
{
    int start = 0;
    int end=n-1;
    while(start<end)
    {
        int mid =(start+end)/2;
        if(arr[mid]>target)
        {
            end =mid;
        }
        else
        start=mid+1;
    }
    return end;
}
int lower(int target)
{
    int start =0;
    int end=n-1;
    while(start<end)
    {
        int mid=(start+end)/2;
        if(arr[mid]>=target)
        end=mid;
        else
        start =mid+1;
    }
    return end;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i = 0 ; i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int m;
    cin>>m;
    for (int i = 0; i < m; i++)
    {
        cin>>fin[i];
    }
    for(int i = 0 ; i<m;i++)
    {
        int up =upper(fin[i]);
        int low =lower(fin[i]);
        if(up==n-1&&arr[n-1]==fin[i])
        up++;

        res[i]=up-low;
    }
    for (int i = 0; i < m; i++)
    {
        cout<<res[i]<<" ";
    }
    

}