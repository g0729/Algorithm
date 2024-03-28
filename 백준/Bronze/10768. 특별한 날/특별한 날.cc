#include<bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

int a,b;
cin>>a>>b;

if(a<2)
cout<<"Before";
else if(a>2)
cout<<"After";
else
{
    if(b<18)
    cout<<"Before";
    else if(b>18)
    cout<<"After";
    else
    cout<<"Special";
}
return 0;
}