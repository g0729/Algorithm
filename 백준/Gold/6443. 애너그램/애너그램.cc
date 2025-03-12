#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int length;
void f(string &s, vector<int> &v, set<string> &se)
{
    if (s.length() == length)
    {
        if (se.find(s) == se.end())
        {
            se.insert(s);
            cout << s << "\n";
        }

        return;
    }

    for (int i = 0; i < 26; i++)
    {
        if (v[i])
        {
            s.push_back(i + 'a');
            v[i]--;
            f(s, v, se);
            s.pop_back();
            v[i]++;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    while (n--)
    {
        string s;
        cin >> s;
        length = s.length();
        vector<int> v(26);
        set<string> se;
        for (int i = 0; i < s.length(); i++)
            v[s[i] - 'a']++;
        string temp;
        f(temp, v, se);
    }
    return 0;
}