#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    string s;
    cin >> n >> s;
    map<char, int> ma = {{'A', 0},
                         {'G', 1},
                         {'C', 2},
                         {'T', 3}};
    char v[4][4] = {{'A', 'C', 'A', 'G'},
                    {'C', 'G', 'T', 'A'},
                    {'A', 'T', 'C', 'G'},
                    {'G', 'A', 'G', 'T'}};

    stack<char>
        st;

    for (int i = 0; i < s.length(); i++)
    {
        st.push(s[i]);
    }

    while (st.size() != 1)
    {
        char a, b, c;
        a = st.top();
        st.pop();
        b = st.top();
        st.pop();
        c = v[ma[a]][ma[b]];
        st.push(c);
    }

    cout << st.top();
    return 0;
}