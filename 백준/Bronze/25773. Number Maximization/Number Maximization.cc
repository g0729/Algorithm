#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000
bool cmp(char a, char b)
{
    return a > b;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    sort(s.begin(), s.end(), cmp);
    cout << s;
    return 0;
}