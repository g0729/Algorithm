#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;

    int idx=0;
    
    int ans=0;

    while(1)
    {
        idx=s.find("EW",idx);
        if(idx==s.npos)
        break;
        idx+=1;
        ans++;
    }
    cout<<ans;
}