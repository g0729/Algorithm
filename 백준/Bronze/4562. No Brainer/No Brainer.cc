#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    while (n--)
    {
        int a, b;
        cin >> a >> b;
        if (a >= b)
            cout << "MMM BRAINS";
        else
            cout << "NO BRAINS";
        cout << "\n";
    }
    return 0;
}