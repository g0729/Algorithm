#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    while (1)
    {

        cin >> s;
        if (s == "0")
            return 0;
        while (1)
        {
            int sum = 0;

            for (int i = 0; i < s.length(); i++)
            {
                sum += s[i] - '0';
            }
            if (sum < 10)
            {
                cout << sum<<"\n";
                break;
            }
            s = to_string(sum);
        }
    }
    return 0;
}