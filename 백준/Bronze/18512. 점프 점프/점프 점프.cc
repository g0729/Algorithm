#include <bits/stdc++.h>
using namespace std;
#define MAX 987654321
#define lint long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x,y,p1,p2;
    cin>>x>>y>>p1>>p2;

    while(1)
    {
        if(p1>p2)
        {
            p2+=y;
        }
        else if(p1<p2)
        {
            p1+=x;
        }
        else
        {
            cout<<p1;
            return 0;
        }
        if(p1>=10000)
        {
            cout<<"-1";
            return 0;
        }
    }
    return 0;
}