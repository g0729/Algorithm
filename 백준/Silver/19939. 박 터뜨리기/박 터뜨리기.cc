    #include <bits/stdc++.h>
    using namespace std;
    #define INF 987654321
    #define lint long long

    int main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n, k;
        cin >> n >> k;

        int sum = k * (k + 1) / 2;

        if (n < sum)
            cout << "-1";
        else
        {
            if ((n - sum) % k == 0)
                cout << k - 1;
            else
                cout << k;
        }
        return 0;
    }