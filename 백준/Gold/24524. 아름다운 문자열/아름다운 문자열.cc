#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s,t;
    cin>>s>>t;
    int cnt[26]={0,};
    for(auto it :s)
    {
        for (int i = 0; i < t.length(); i++)
        {
            if(it==t[i])
            {
                if(i==0)
                {
                    cnt[0]++;
                }
                else if(cnt[i-1]>cnt[i])
                {
                    cnt[i]++;
                }
            }
        }       
    }
    cout<<cnt[t.length()-1];
}