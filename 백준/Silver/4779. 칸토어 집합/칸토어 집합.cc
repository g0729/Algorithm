#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321

void f(int len)
{
    if (len == 3)
    {
        cout << "- -";
        return;
    }

    f(len / 3);
    for (int i = 0; i < len / 3; i++)
        cout << " ";
    f(len / 3);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (1)
    {
        int n;
        cin >> n;
        if (cin.eof())
            break;
        if (n == 0)
        {
            cout << "-\n";
            continue;
        }
        else
            f(pow(3, n));
        cout << "\n";
    }
    return 0;
}