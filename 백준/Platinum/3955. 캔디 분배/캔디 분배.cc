#include<bits/stdc++.h>
using namespace std;
#define lint  long long
#define MAX 1000000000
lint  EEA(lint  a, lint  b)
{
    lint  r0 = a, r1 = b;
    lint  s0 = 1, s1 = 0;
    lint  t0 = 0, t1 = 1;
    lint  temp = 0, q = 0;

    while (r1) {
        q = r0 / r1;
        temp = r0;
        r0 = r1;
        r1 = temp - r1 * q;
        temp = s0;
        s0 = s1;
        s1 = temp - s1 * q;
        temp = t0;
        t0 = t1;
        t1 = temp - t1 * q;
    }
    while (t0 < 0)
    {
        t0 += a;
    }
    return t0;
}
lint  gcd(lint  a, lint  b)
{
    lint  c = a % b;
    while (c != 0)
    {
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}
int  main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        lint  a, b;
        cin >> a >> b;
        if (a == 1)
        {
            if (b == 1)
            {
                cout << "2\n";
                continue;
            }
            cout << "1\n";
            continue;
        }
        if (b == 1) 
        {
            if (a + 1 > MAX)
            {
                cout << "IMPOSSIBLE\n";
                continue;
            }
            else
            {
                cout << a + 1<<"\n";
                continue;
            }
        }
        if (gcd(a, b) != 1)
        {
            cout<< "IMPOSSIBLE\n";
            continue;
        }
        lint res = EEA(a, b);
        while (res > a)
        {
            res -= a;
        }
        if (res > MAX)
        {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        else
        {
            cout << res << "\n";
            continue;
        }
    }
}