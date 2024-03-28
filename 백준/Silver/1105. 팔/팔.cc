#include <bits/stdc++.h>
using namespace std;

int main()
{
   string l,r;
   cin>>l>>r;
   if(l.length()!=r.length())
   {
       cout<<"0";
       return 0;
   }
   int cnt=0;
   for (int i = 0; i < l.length(); i++)
   {
      if(l[i]==r[i])
      {
          if(l[i]=='8')
          {
              cnt++;
          }
      }
      else
      break;
   }
   cout<<cnt;
}