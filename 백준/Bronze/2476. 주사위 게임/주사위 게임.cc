#include <bits/stdc++.h>
using namespace std;

int main()
{
    int res = 0;

    int t;
    cin>>t;
    while (t--)
    {
        int a, b, c;

        cin >> a >> b >> c;
        int temp;
        if (a == b && b == c && a == c)
        {
            temp= 10000 + 1000 * a;
        }
        else if (a == b)
        {
            temp= 1000 + 100 * a;
        }
        else if (a == c)
        {
            temp = 1000 + 100 * a;
        }
        else if (b == c)
        {
            temp = 1000 + 100 * b;
        }
        else
        {
            a = max(a, b);
            a = max(a, c);
            temp = 100 * a;
        }
        res=max(res,temp);
    }

    cout<<res;
}