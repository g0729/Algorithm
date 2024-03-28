#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
int graph[MAX];
int n;
bool binarysearch(int target)
{
    int start=0;
    int end =n-1;
    
    while(start<=end)
    {
        int mid =(start+end)/2;
        if(graph[mid]==target)
        return true;
        else if(graph[mid]<target)
        {
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>graph[i];
    }
    sort(graph,graph+n);
    int m;
    cin>>m;
    for(int i = 0 ; i<m;i++)
    {
        int target;
        cin>>target;
        if(binarysearch(target))
        cout<<"1\n";
        else
        cout<<"0\n";
    }
}