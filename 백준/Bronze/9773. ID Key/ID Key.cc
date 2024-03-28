#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;
        int sum = 0;

        for (int i = 0; i < s.length(); i++)
        {
            sum += s[i] - '0';
        }

        string temp = s.substr(10);

        sum += stoi(temp) * 10;
        if (sum < 1000)
            sum += 1000;

        sum %= 10000;

        cout <<std::setfill('0')<< std::setw(4) << sum << "\n";
        
    }
    return 0;
}