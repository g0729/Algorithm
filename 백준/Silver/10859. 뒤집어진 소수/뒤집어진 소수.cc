#include <bits/stdc++.h>
using namespace std;
#define MAX 987654321
#define lint long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    lint n;
    lint rn;
    string s;
    string temp;
    cin>>s;
    if(s=="1")
    {
        cout<<"no";
        return 0;
    }
    n=stold(s);
    for (int i = s.length()-1; i >=0 ; i--)
    {
        if (s[i] == '1')
            temp += '1';
        else if (s[i] == '6')
            temp += '9';
        else if (s[i] == '9')
            temp += '6';
        else if (s[i] == '3' || s[i] == '4' || s[i] == '7')
        {
            cout << "no";
            return 0;
        }
        else
            temp += s[i];
    }
    rn=stold(temp);

    for (lint i = 2; i*i <= n; i++)
    {
        if(n%i==0)
        {
            cout<<"no";
            return 0;
        }
    }
    for (lint i = 2; i*i <= n; i++)
    {
        if(rn%i==0)
        {
            cout<<"no";
            return 0;
        }
    }

    cout<<"yes";
}