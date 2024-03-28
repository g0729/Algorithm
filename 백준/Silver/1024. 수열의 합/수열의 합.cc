#include <bits/stdc++.h>
using namespace std;
#define lint long long

int main()
{
    lint n, l;

    cin >> n >> l;

    if ((l - 1) * l > 2 * n)
    {
        cout << "-1";
        return 0;
    }

    for (;; l++)
    {
        if(l>100)
        {
            cout<<"-1";
            return 0;
        }
        if ((2 * n) % l == 0)
        {
            lint temp = (2 * n) / l - l + 1;
            if (temp < 0)
            {
                cout << "-1";
                return 0;
            }
            if (temp % 2 == 0)
            {
                lint a = temp / 2;
                for (int i = 0; i < l; i++)
                {
                    cout << a + i << " ";
                }
                return 0;
            }
        }
    }
}