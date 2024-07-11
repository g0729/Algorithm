#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321

string s;
vector<char> v(52);

void print()
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            cout << v[s[i] - 'A'];
        else
            cout << v[s[i] - 'a' + 26];
    }
    cout << "\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> s >> n;

    for (int i = 0; i < 26; i++)
    {
        v[i] = i + 'A';
        v[i + 26] = i + 'a';
    }

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (a == 2)
            print();
        else
        {
            char b, c;
            cin >> b >> c;

            for (int j = 0; j < 52; j++)
            {
                if (v[j] == b)
                    v[j] = c;
            }
        }
    }

    return 0;
}