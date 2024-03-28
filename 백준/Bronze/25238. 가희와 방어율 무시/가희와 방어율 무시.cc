#include <bits/stdc++.h>
using namespace std;

int main()
{

    double a, b;
    cin >> a >> b;

    a = a - a * (b/ 100);
    if (a >= 100)
        cout << "0";
    else
        cout << "1";
}