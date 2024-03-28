#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> v;

    v.push_back(0);

    bool flag = false;
    for (int i = 1; i < 1000; i++)
    {
        for (int j = 0; j < i; j++)
        {
            v.push_back(i);

            if (v.size() > 1001)
            {
                flag = true;
                break;
            }
        }
        if (flag)
            break;
    }

    int a, b;

    cin >> a >> b;

    int sum = 0;

    for (int i = a; i <= b; i++)
    {
        sum += v[i];
    }

    cout << sum;
    return 0;
}