#include<bits/stdc++.h>
using namespace std;
bool check[2000001];
int arr[20];
int n;
void f(int now,int sum)
{
    check[sum]=true;
    if(now==n)
    return;
    
    f(now+1,sum);
    f(now+1,sum+arr[now]);
}
int main()
{
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    f(0,0);
    int i=1;
    while(check[i])
    i++;
    cout<<i;
    
}