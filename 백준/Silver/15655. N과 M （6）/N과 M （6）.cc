#include <bits/stdc++.h>
using namespace std;
int sel[8];
int arr[8];
int n, m;
void print()
{
    for (int i = 0; i < n; i++)
    {
        if(sel[i])
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void dfs(int idx,int cnt)
{
    if(cnt==m)
    {
        print();
        return;
    }
    for(int i =idx;i<n;i++)
    {
        if(sel[i])
        continue;
        sel[i]=true;
        dfs(i,cnt+1);
        sel[i]=false;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr,arr+n);
    dfs(0,0);
}