#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string s;
        getline(cin,s);

        for (int i = s.length()-1; i >=0; i--)
        {
            cout<<s[i];
        }
        cout<<endl;
    }
}