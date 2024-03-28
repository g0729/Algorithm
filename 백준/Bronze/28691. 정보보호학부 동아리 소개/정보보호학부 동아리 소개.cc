#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    char c;
    cin >> c;

    if (c == 'M')
        cout << "MatKor";
    else if (c == 'W')
        cout << "WiCys";
    else if (c == 'C')
        cout << "CyKor";
    else if (c == 'A')
        cout << "AlKor";
    else
        cout << "$clear";
    return 0;
}