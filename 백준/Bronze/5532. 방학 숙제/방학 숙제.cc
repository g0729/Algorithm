#include <bits/stdc++.h>
using namespace std;

int main()
{
    int l, a, b, c, d;

    cin >> l >> a >> b >> c >> d;

    int a_res, b_res;

    a_res = a / c;
    if (a % c != 0)
        a_res++;

    b_res = b / d;
    if (b % d != 0)
        b_res++;

    a_res = max(a_res, b_res);

    cout << l - a_res;
}