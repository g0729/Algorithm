#include<bits/stdc++.h>
using namespace std;
#define MAX 500000
int arr[MAX];
int res[MAX];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for (int  i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int m;
    cin>>m;
    for (int i = 0; i < m; i++)
    {
        int a;
        cin>>a;
        int temp=binary_search(arr,arr+n,a);
        res[i]=temp;
    }
    for (int i = 0; i < m; i++)
    {
        cout<<res[i]<<" ";
    }
    
}