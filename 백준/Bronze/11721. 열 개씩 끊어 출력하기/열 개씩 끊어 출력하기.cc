#include<bits/stdc++.h>
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

for (int i = 1; i <= s.length(); i++)
{
    cout<<s[i-1];
    if(i%10==0)
    cout<<"\n";
}

return 0;
}