#include<bits/stdc++.h>
using namespace std;
#define lint long long
lint fib[1010100];
string s;
lint q,m;
lint t;

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    cin>>q>>m;

    fib[0]=fib[1]=1;

    for(lint i =2 ; i<m*m;i++)
    {
        fib[i]=(fib[i-1]+fib[i-2])%m;
        if(fib[i]==1&&fib[i-1]==1)
        {
            t=i-1;
            break;
        }
    }
    for(lint i = 0 ; i<t;i++)
    {
        s += to_string(fib[i]);
    }
    if (m == 2)
        s= "110";
    else if (m == 3)
        s= "11202210";
    t=s.size();

    while(q--)
    {
        lint n;
        cin>>n;
        cout<<s[((n%t)+t-1)%t]<<"\n";
    }
}