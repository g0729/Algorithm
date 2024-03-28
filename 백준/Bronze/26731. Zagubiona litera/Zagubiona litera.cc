#include<bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

bool alpha[26];
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
string s;
cin>>s;

for (int i = 0; i < s.length(); i++)
{
    alpha[s[i]-'A']=true;
}

for (int i = 0; i < 26; i++)
{
    char c;
    if(!alpha[i])
    {
        c=i+'A';
        cout<<c;
    }
}

return 0;
}