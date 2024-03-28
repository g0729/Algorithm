#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int arr[MAX];
vector<int>v;
int n;
int gcd(int a,int b)
{
    if(b==0)
    return a;
    else
    return gcd(b,a%b);
}
int main()
{
    cin>>n;
    for(int i = 0 ; i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i = 0 ; i<n-1;i++)
    {
        v.push_back(abs(arr[i+1]-arr[i]));
    }
    int temp;
    if(n==2)
    {
        temp=abs(v[0]-v[1]);
    }
    else
    {
        temp=gcd(v[0],v[1]);
    }
    for(int i = 2;i<v.size();i++)
    {
        temp=gcd(temp,v[i]);
    }
    cout<<temp;
}