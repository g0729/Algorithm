#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321

void reverse(string &s)
{
    for (int i = 0; i < s.length() / 2; i++)
    {
        char temp = s[i];
        s[i] = s[s.length() - i - 1];
        s[s.length() - i - 1] = temp;
    }
}

string my_plus(string a, string b)
{
    string res;
    reverse(a);
    reverse(b);

    while (a.length() != b.length())
    {
        if (a.length() > b.length())
            b += '0';
        else
            a += '0';
    }
    int carry = 0;
    int sum;
    for (int i = 0; i < a.length(); i++)
    {
        sum = a[i] - '0' + b[i] - '0' + carry;

        if (sum >= 10)
        {
            carry = 1;
            sum -= 10;
        }
        else
            carry = 0;
        res += sum + '0';
    }

    if (carry == 1)
        res += '1';
    reverse(res);
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    string s_2, s_1, s;
    if (n <= 2)
    {
        cout << "1";
        return 0;
    }
    s_2 = "1";
    s_1 = '1';

    for (int i = 3; i <= n; i++)
    {
        s = my_plus(s_2, s_1);
        s_2 = s_1;
        s_1 = s;
    }
    cout << s;
    return 0;
}