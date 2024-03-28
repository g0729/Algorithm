#include <bits/stdc++.h>
using namespace std;

#define lint long long

lint GCD(lint a, lint b)
{
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}
int main()
{
    lint gcd, lcm;
    cin >> gcd >> lcm;

    lint temp = lcm/gcd;


    lint resA;
    lint resB;

    for (lint i = 1; i * i <= temp; i++)
    {
        if (temp % i == 0)
        {
            if(GCD(i,temp/i)==1)
            {
                resA=i;
                resB=temp/i;
            }
        }
    }

    cout << resA*gcd << " " << resB*gcd;
}