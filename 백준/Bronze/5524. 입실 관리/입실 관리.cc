#include<bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

int t;
cin>>t;
while(t--)
{
    string s;
    cin>>s;

    for(int i = 0 ; i<s.length();i++)
    {
        s[i]=tolower(s[i]);
    }
    cout<<s<<"\n";
}
return 0;
}