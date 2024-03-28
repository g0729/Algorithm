#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 1;; i++)
    {
        string s;
        cin >> s;

        if (s[0] == '-')
            break;

        stack<char> st;
        int res = 0;

        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];

            if (st.empty())
            {
                if (c == '}')
                    res++;
                st.push('{');
            }
            else
            {
                if (st.top() == '{' && c == '}')
                    st.pop();
                else
                    st.push(c);
            }
        }
        res+=st.size()/2;

        cout<<i<<". "<<res<<"\n";

    }

    return 0;
}