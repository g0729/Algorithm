#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,a,b;
    pair<int,int>arr[10];
    cin>>n>>a>>b;
    for (int i = 0; i < 10; i++)
    {
        cin>>arr[i].first>>arr[i].second;
    }
    n=8-n;
    for (int i = 0; i < n; i++)
    {
        a+=arr[i].first*3;
        b+=arr[i].first*3;
        if(6-arr[i].first>=arr[i].second)
        {
            b+=3*arr[i].second;
        }
        else
        {
            b+=(6-arr[i].first)*3;
        }
    }
    
    if(a>=66&&b>=130)
    {
        cout<<"Nice";
    }
    else
    {
        cout<<"Nae ga wae"; 
    }
}