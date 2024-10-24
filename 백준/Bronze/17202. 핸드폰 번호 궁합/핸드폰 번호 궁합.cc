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
    string a, b;
    cin >> a >> b;
    string s;
    for (int i = 0; i < a.length(); i++)
    {
        s.push_back(a[i]);
        s.push_back(b[i]);
    }
    while (s.length() != 2)
    {
        string temp;
        for (int i = 0; i < s.length() - 1; i++)
        {
            char num = (s[i] + s[i + 1] - '0' * 2) % 10 + '0';
            temp.push_back(num);
        }
        s = temp;
    }

    cout << s;
    return 0;
}