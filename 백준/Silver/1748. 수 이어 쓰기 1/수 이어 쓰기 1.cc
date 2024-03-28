#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    lint n;
    cin>>n;
    lint res=0;

    lint num=10;
    lint digit=1;
    while(1)
    {
        if(n<num)
        {
            lint temp=n-num/10+1;
            res+=temp*digit;
            break;
        }
        else
        {
            res=res+(num-num/10)*digit;
            num*=10;
            digit++;
        }
    }
    cout<<res;
    return 0;
}