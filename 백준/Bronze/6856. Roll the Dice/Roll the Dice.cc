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

        int res = 0;
        int a, b;
        cin >> a >> b;

        for (int i = 1; i <= a; i++)
        {
            for (int j = 1; j <= b; j++)
            {
                if (i + j == 10)
                    res++;
            }
        }

        if (res == 1)
        {
            cout << "There is 1 way to get the sum 10.";
        }
        else
        {
            cout << "There are " << res << " ways to get the sum 10.";
        }
        return 0;
    }