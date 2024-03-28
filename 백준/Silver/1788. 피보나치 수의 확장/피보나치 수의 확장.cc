    #include <bits/stdc++.h>
    using namespace std;
    #define MOD 1000000000

    int main()
    {
        int n;

        cin >> n;

        if (n == 0)
        {
            cout << "0\n0";
            return 0;
        }
        else if (n == 1 || n == -1)
        {
            cout << "1\n1";
            return 0;
        }

        bool sign;

        if (n < 0)
            sign = 0;
        else
            sign = 1;

        n = abs(n);

        if (sign)
        {
            int res;
            int temp1 = 1;
            int temp2 = 0;

            for (int i = 2; i <= n; i++)
            {
                res = (temp1 + temp2) % MOD;
                temp2 = temp1;
                temp1 = res;
            }
            cout << "1\n";
            cout << res;
        }
        else
        {
            int res;
            int temp1 = 1;
            int temp2 = 0;
            for (int i = 1; i <= n; i++)
            {
                res = (temp1 - temp2) % MOD;
                temp1 = temp2;
                temp2 = res;
            }
            if (res == 0)
                cout << "0\n0";
            else if (res < 0)
                cout << "-1\n"
                    << abs(res);
            else
                cout << "1\n"
                    << res;
        }
    }