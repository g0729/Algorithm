#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    stack<pair<int, bool>> st;
    stack<char> st2;
    string s;
    cin >> s;

    for (auto it : s)
    {
        if (it == '(' || it == '[')
            st2.push(it);
        if (it == ')')
        {
            if (st2.empty() || st2.top() != '(')
            {
                cout << "0";
                return 0;
            }
            else
                st2.pop();
        }
        if (it == ']')
        {
            if (st2.empty() || st2.top() != '[')
            {
                cout << "0";
                return 0;
            }
            else
                st2.pop();
        }
    }

    if (!st2.empty())
    {
        cout << "0";
        return 0;
    }

    for (auto it : s)
    {
        if (it == '(' || it == '[')
            st.push({it, false});
        else
        {
            int temp = 0;

            if (it == ']')
            {
                while (st.top().first!='['&&st.top().second!=false && !st.empty())
                {
                    temp+=st.top().first;
                    st.pop();
                }
                st.pop();
                if(temp==0)
                    st.push({3,true});
                else
                {
                    st.push({temp*3,true});
                }
            }
            else if (it == ')')
            {
                while (st.top().first!='('&&st.top().second!=false && !st.empty())
                {
                    temp+=st.top().first;
                    st.pop();
                }
                st.pop();
                if(temp==0)
                    st.push({2,true});
                else
                {
                    st.push({temp*2,true});
                }
            }
     
        }
    }

    int res=0;

    while(!st.empty())
    {
        res+=st.top().first;
        st.pop();
    }

    cout<<res;
    return 0;
}