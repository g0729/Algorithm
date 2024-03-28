#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N,m,M,T,R;

    cin>>N>>m>>M>>T>>R;

    int res=0;
    int now=m;

    while(1)
    {
        if(now+T<=M)
        {
            N--;
            now=now+T;
        }
        else
        {
            now=max(now-R,m);
        }
        res++;
        if(res>=1e6)
        {
            cout<<"-1";
            return 0;
        }
        if(N==0)
        break;
        
    }

    cout<<res;
    return 0;
}