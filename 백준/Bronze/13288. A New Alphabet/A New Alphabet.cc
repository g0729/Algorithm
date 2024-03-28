#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

string v[26] = {"@", "8", "(", "|)", "3",

                "#", "6", "[-]", "|", "_|",

                "|<", "1", "[]\\/[]", "[]\\[]", "0",

                "|D", "(,)", "|Z", "$", "']['",

                "|_|", "\\/", "\\/\\/", "}{", "`/", "2"};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    getline(cin, s);

    string res;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            res += v[s[i] - 'A'];
        else if (s[i] >= 'a' && s[i] <= 'z')
            res += v[s[i] - 'a'];
        else
            res += s[i];
    }

    cout << res;
    return 0;
}