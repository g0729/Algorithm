#include <bits/stdc++.h>
using namespace std;
#define MAX 987654321

int main()
{
    while (1)
    {
        long long n;

        cin >> n;
        if (cin.eof())
            break;
        bool check[10] = {
            0,
        };

        long long k = 1;

        while (1)
        {
            long long cn = n * k;

            string s = to_string(cn);

            for (int i = 0; i < s.length(); i++)
            {
                check[s[i] - '0'] = true;
            }

            bool flag = true;

            for (int i = 0; i < 10; i++)
            {
                if (!check[i])
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
            {
                cout << k << endl;
                break;
            }
            k++;
        }
    }
    return 0;
}