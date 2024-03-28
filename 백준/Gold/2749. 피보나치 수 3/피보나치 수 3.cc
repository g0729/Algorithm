#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000
#define MAX 1500000
#define lint long long
lint arr[MAX+1];
int main()
{
    arr[0]=0;
    arr[1]=1;
    for(int i = 2 ; i<=MAX;i++)
    {
        arr[i]=(arr[i-1]+arr[i-2])%MOD;
    }
    lint n;
    cin>>n;
    cout<<arr[n%MAX];
}