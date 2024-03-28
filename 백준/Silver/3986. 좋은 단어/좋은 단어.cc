#include <bits/stdc++.h>
using namespace std;
#define MAX 987654321

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int res=n;

    while (n--)
    {
        stack<char>st;
        string s;

        cin>>s;

        for (int i = 0; i < s.length(); i++)
        {
            if(st.empty())
            {
                st.push(s[i]);
            }
            else if(st.top()==s[i])
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
        
        if(!st.empty())
        res--;
    }

    cout<<res;
        
    return 0;
}