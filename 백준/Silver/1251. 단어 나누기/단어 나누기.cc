#include <bits/stdc++.h>
using namespace std;

void reverse(string & s)
{
    for (int i = 0; i < s.length()/2; i++)
    {
        char temp=s[i];
        s[i]=s[s.length()-i-1];
        s[s.length()-i-1]=temp;
    }
    
}
int main()
{
    vector<string> v;

    string s;

    cin >> s;

    for (int i = 1; i < s.length() - 1; i++)
    {
        for (int j = i + 1; j < s.length() ; j++)
        {
            string s1,s2,s3;

            s1=s.substr(0,i);
            s2=s.substr(0,j);
            s2=s2.substr(i,j-i);
            s3=s.substr(j);
            reverse(s1);
            reverse(s2);
            reverse(s3);
            s1=s1+s2+s3;

            v.push_back(s1);
        }
    }

    sort(v.begin(),v.end());

    cout<<v[0];
}