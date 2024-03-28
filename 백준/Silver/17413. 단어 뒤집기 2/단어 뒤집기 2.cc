#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    string res;
    getline(cin, s);
    stack<char> q;
    bool check = false;
    for (int i = 0; i < s.length(); i++)
    {
       if(s[i]=='<')
       {
           check=true;
           if(!q.empty())
           {
               while(!q.empty())
               {
                   res+=q.top();
                   q.pop();
               }
               res+='<';
               continue;
           }
       }
       if(s[i]==' ')
       {
           while(!q.empty())
           {
               res+=q.top();
               q.pop();
           }
           res+=' ';
           continue;
       }
       if(check)
       {
           res+=s[i];
       }
       else
       {
           q.push(s[i]);
       }
       if(s[i]=='>')
       {
           check=false;
       }
       
    }
    while (!q.empty())
    {
        res += q.top();
        q.pop();
    }
    cout << res;
}