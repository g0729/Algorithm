#include<bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

while(1)
{
    ll n,k;
    cin>>n>>k;
    if(cin.eof())
        break;
    
    ll res=0;
    ll stamp=0;
    
    while(1)
    {
        res+=n;
        stamp+=n;
        n=stamp/k;
        stamp%=k;
        if(!n)
            break;
    }
    cout<<res<<"\n";
}
return 0;
}