#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;

    set<string>se;

    cin>>s;

    for (int i = 0; i < s.length(); i++)
    {
        for (int j = 0; j <= s.length()-i; j++)
        {
            string temp=s.substr(i,j);
            se.insert(temp);
        }
    }
    
    cout<<se.size()-1;    
}