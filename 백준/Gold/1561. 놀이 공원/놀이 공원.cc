#include <bits/stdc++.h>
using namespace std;
#define MAX 10000
#define lint long long
lint n, m;
lint arr[MAX];
lint res = 99999999999;
lint check(lint target)
{
    lint res = 0;
    for (int i = 0; i < m; i++)
    {
        res += target / arr[i] + 1;
    }
    return res;
}
void binsearch()
{
    lint start = 0;
    lint end = 30 * n;
    while (start <= end)
    {
        lint mid = (start + end) / 2;
        lint temp = check(mid);
        if (temp >= n)
        {

            res = min(res, mid);
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }
    binsearch();
    lint temp = check(res);
    if (n <= m)
    {
        cout << n;
    }
    else
    {
        temp = temp - n;
        if (temp)
        {
            for (int i = m - 1; i >= 0; i--)
            {
                if (res % arr[i] == 0)
                {
                   if(temp==0)
                   cout<<i+1;
                   temp--;
                }
            }
        }
        else
        {
            for (int i = m - 1; i >= 0; i--)
            {
                if (res % arr[i] == 0)
                {
                    cout << i + 1;
                    break;
                }
            }
        }
    }
}