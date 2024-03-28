#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

bool cmp(string a, string b)
{
    if (a.length() == b.length())
    {
        int aSum = 0;
        int bSum = 0;

        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] >= '0' && a[i] <= '9')
                aSum += a[i] - '0';
            if (b[i] >= '0' && b[i] <= '9')
                bSum += b[i] - '0';
        }
        if (aSum != bSum)
            return aSum < bSum;

        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] == b[i])
                continue;
            return a[i] < b[i];
        }
    }
    else
        return a.length() < b.length();
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<string> v;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        v.push_back(s);
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << "\n";
    }

    return 0;
}