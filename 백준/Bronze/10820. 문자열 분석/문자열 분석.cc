#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;

    while(1)
    {
        getline(cin,s);
        if(cin.eof())
        break;
        int cnt_num=0;
        int cnt_cap=0;
        int cnt_spa=0;
        int cnt_sma=0;

        for (int i = 0; i < s.length(); i++)
        {
            if(s[i]==' ')
                cnt_spa++;
            else if(s[i]>='a'&&s[i]<='z')
                cnt_sma++;
            else if(s[i]>='A'&&s[i]<='Z')
                cnt_cap++;
            else
                cnt_num++;
        }
        
        cout<<cnt_sma<<" "<<cnt_cap<<" "<<cnt_num<<" "<<cnt_spa<<endl;
    }
}