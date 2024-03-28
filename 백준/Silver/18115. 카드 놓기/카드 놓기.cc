#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    deque<int> dq;
    stack<int> st;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        dq.push_back(i);

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            st.push(dq.front());
            dq.pop_front();
        }
        if (a == 2)
        {
            st.push(dq[1]);
            dq.erase(dq.begin() + 1);
        }
        if (a == 3)
        {
            st.push(dq.back());
            dq.pop_back();
        }
    }

    vector<int> res(n);

    for (int i = 1; i <= n; i++)
    {
        res[st.top() - 1] = i;
        st.pop();
    }

    for (int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}