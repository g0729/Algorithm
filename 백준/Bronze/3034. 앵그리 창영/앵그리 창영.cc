#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, w, h;
    cin >> n >> w >> h;

    double temp = sqrt((double)w * w + (double)h * h);

    while (n--)
    {
        int a;
        cin >> a;
        if (a <= temp)
            cout << "DA";
        else
            cout << "NE";
        cout << "\n";
    }
    return 0;
}