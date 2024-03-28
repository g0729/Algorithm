#include<bits/stdc++.h>
using namespace std;

int main()
{
   string s;
   cin>>s;
   int temp=0;
   int cnt=1;
   if(s.length()==1)
   {
    temp=stoi(s);
    cout<<"0"<<endl;
    if(temp%3==0)
    {
        cout<<"YES";
    }   
    else
    {
        cout<<"NO";
    }
    return 0;
   }
   for (int i = 0; i < s.length(); i++)
   {
       temp+=s[i]-'0';
   }
   while(temp>=10)
   {
       string a=to_string(temp);
       int b=0;
       for (int i = 0; i < a.length(); i++)
       {
           b+=a[i]-'0';
       }
       temp=b;
       cnt++;
   }
   cout<<cnt<<endl;
   if(temp%3==0)
   {
       cout<<"YES";
   }
   else
   cout<<"NO";
}