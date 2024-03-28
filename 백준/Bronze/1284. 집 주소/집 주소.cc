#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(1)
    {
        string s;
        cin>>s;
        if(s=="0")
        break;

        int res=0;

        res+=s.length()+1;

        for (int i = 0; i < s.length(); i++)
        {
            if(s[i]=='0')
            res+=4;
            else if(s[i]=='1')
            res+=2;
            else
            res+=3;
        }
        
        cout<<res<<"\n";
    }
    return 0;
}