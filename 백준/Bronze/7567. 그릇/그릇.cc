#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;

    cin>>s;

    int res=10;

    for (int i = 1; i < s.length(); i++)
    {
        if(s[i-1]==s[i])
        res+=5;
        else
        res+=10;
    }
    
    cout<<res;
    return 0;
}