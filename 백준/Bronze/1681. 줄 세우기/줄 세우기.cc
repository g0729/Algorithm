#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000

bool check(string &s, int& l)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '0' + l)
            return false;
    }

    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, l;
    cin >> n >> l;
    int cnt = 0;
    for (int i = 1;; i++)
    {
        string temp=to_string(i);
        if(check(temp,l))
        {
            cnt++;   
        }

        if(cnt==n)
        {
            cout<<i;
            return 0;
        }
    }

    return 0;
}