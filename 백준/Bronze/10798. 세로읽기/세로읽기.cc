#include<bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

vector<char>v[15];

for (int i = 0; i < 5; i++)
{
    string s;
    cin>>s;

    for (int j = 0; j < s.length(); j++)
    {
        v[j].push_back(s[j]);
    }
}


for (int i = 0; i < 15; i++)
{
    for (int j = 0; j < v[i].size(); j++)
    {
        cout<<v[i][j];
    }
    
}

return 0;
}