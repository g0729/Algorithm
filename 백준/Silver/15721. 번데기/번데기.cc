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

    int a, t, target;
    cin >> a >> t >> target;
    int round = 2;
    int now = 0;
    int cnt = 0;
    int i = 0;
    while (1)
    {
        now = 0;
        if (now == target)
            cnt++;
        if (cnt == t)
            break;
        i++;
        now = 1;
        if (now == target)
            cnt++;
        if (cnt == t)
            break;
        i++;
        now = 0;
        if (now == target)
            cnt++;
        if (cnt == t)
            break;
        i++;
        now = 1;
        if (now == target)
            cnt++;
        if (cnt == t)
            break;
        i++;
        bool flag = false;
        now = 0;
        for (int j = 0; j < round; j++)
        {
            if (now == target)
                cnt++;
            if (cnt == t)
            {
                flag = true;
                break;
            }
            i++;
        }
        if (flag)
            break;

        now = 1;
        for (int j = 0; j < round; j++)
        {
            if (now == target)
                cnt++;
            if (cnt == t)
            {
                flag = true;
                break;
            }
            i++;
        }
        if (flag)
            break;
        round++;
    }
    cout << i % a;
    return 0;
}