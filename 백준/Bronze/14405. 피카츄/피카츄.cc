#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    int idx = 0;
    bool flag = true;
    while (idx < s.length())
    {
        if (s[idx] == 'p')
        {
            if (idx + 1 < s.length())
            {
                if (s[idx + 1] == 'i')
                    idx += 2;
                else
                {
                    flag = false;
                    break;
                }
            }
            else
            {
                flag = false;
                break;
            }
        }
        else if (s[idx] == 'k')
        {
            if (idx + 1 < s.length())
            {
                if (s[idx + 1] == 'a')
                    idx += 2;
                else
                {
                    flag = false;
                    break;
                }
            }
            else
            {
                flag = false;
                break;
            }
        }
        else if (s[idx] == 'c')
        {
            if (idx + 2 < s.length())
            {
                if (s[idx + 1] == 'h' && s[idx + 2] == 'u')
                    idx += 3;
                else
                {
                    flag = false;
                    break;
                }
            }
            else
            {
                flag = false;
                break;
            }
        }
        else
        {
            flag = false;
            break;
        }
    }

    if (flag)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}