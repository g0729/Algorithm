#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

string reverse(string &s)
{
    string temp;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        temp += s[i];
    }
    return temp;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    set<string> se;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        se.insert(s);
    }
    for (auto it : se)
    {
        string temp = reverse(it);
        if (se.find(temp) != se.end())
        {
            cout << it.length() << " " << it[it.length() / 2];
            break;
        }
    }
    return 0;
}