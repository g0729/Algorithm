#include<bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

int A,B;
cin>>A>>B;
int a=A+B;
int b=A-B;

if(A<B)
    cout<<"-1";
else
{
    if(a%2!=0|b%2!=0)
    {
        cout<<"-1";
    }
    else
    {
        cout<<a/2<<" "<<b/2;
    }
}
return 0;
}