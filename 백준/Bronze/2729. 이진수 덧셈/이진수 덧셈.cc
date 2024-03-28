#include <bits/stdc++.h>
using namespace std;

void reverse(string &s)
{
    for (int i = 0; i < s.length() / 2; i++)
    {
        char temp = s[i];
        s[i] = s[s.length() - i - 1];
        s[s.length() - i - 1] = temp;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        if (a.length() < b.length())
        {
            string temp = a;
            a = b;
            b = temp;
        }

        reverse(a);
        reverse(b);
        int length=a.length()-b.length();
        for (int i = 0; i < length; i++)
        {
            b.push_back('0');
        }
        int carry = 0;

        string res;

        for (int i = 0; i < a.length(); i++)
        {
            int sum = a[i] - '0' + b[i] - '0' + carry;

            if (sum >= 2)
            {
                carry = 1;
                sum = sum % 2;
            }
            else
            {
                carry = 0;
            }
            res += sum + '0';
        }
        if (carry == 1)
            res += '1';
        reverse(res);
        int k = 0;
        while (1)
        {
            if (res[k] == '0')
                k++;
            else
                break;
        }
        res = res.substr(k);
        if(res.empty())
        cout<<"0\n";
        else
        cout << res << "\n";
    }
}