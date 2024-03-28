#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;

    cin >> s;

    int n = 1;

    int now=0;

    while(1)
    {
        string temp=to_string(n);
        bool flag=false;
        for(int i = 0 ; i<temp.length();i++)
        {
            if(temp[i]==s[now])
            {
                now++;
            }
            if(now==s.length())
            {
                flag =true;
                break;
            }
        }
        if(flag)
        {
            cout<<n;
            break;
        }
        n++;
    }
}