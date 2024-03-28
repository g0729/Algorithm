#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<string> se;

    int n;
    cin>>n;

    int res=0;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin>>s;

        if(se.find(s)==se.end())
        {
            res++;
            for (int i = 0; i < s.length(); i++)
            {
                string temp=s.substr(1);
                temp.push_back(s[0]);
                se.insert(temp);
                s=temp;
            }   
        }        
    }

    cout<<res;
}