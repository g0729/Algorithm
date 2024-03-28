#include <bits/stdc++.h>
using namespace std;

struct stats
{
    double a, b, c, d, e;
};
double cal(stats s)
{
    double res;
    res = s.a * (1 + s.b / 100) * (1 - min(1.0, s.c / 100) + min(s.c / 100, 1.0) * s.d / 100) * (1 + s.e / 100);
    return res;
}
int main()
{
    stats s[4];

    for (int i = 0; i < 4; i++)
    {
        cin >> s[i].a >> s[i].b >> s[i].c >> s[i].d >> s[i].e;
    }

    double nowA, nowB;
    nowA = cal(s[0]);
    nowB = cal(s[1]);

    for (int i = 0; i < 2; i++)
    {
        s[i].a -= s[i + 2].a;
        s[i].b -= s[i + 2].b;
        s[i].c -= s[i + 2].c;
        s[i].d -= s[i + 2].d;
        s[i].e -= s[i + 2].e;
    }

    s[0].a += s[3].a;
    s[0].b += s[3].b;
    s[0].c += s[3].c;
    s[0].d += s[3].d;
    s[0].e += s[3].e;
    s[1].a += s[2].a;
    s[1].b += s[2].b;
    s[1].c += s[2].c;
    s[1].d += s[2].d;
    s[1].e += s[2].e;

    double afterA, afterB;
    afterA = cal(s[0]);
    afterB = cal(s[1]);

    if (nowA > afterA)
        cout << "-\n";
    else if (nowA < afterA)
        cout << "+\n";
    else
        cout << "0\n";

    if (nowB > afterB)
        cout << "-\n";
    else if (nowB < afterB)
        cout << "+\n";
    else
        cout << "0\n";
}