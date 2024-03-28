#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    map<string, double> ma = {{"A+", 4.5}, {"A0", 4.0}, {"B+", 3.5}, {"B0", 3.0}, {"C+", 2.5}, {"C0", 2.0}, {"D+", 1.5}, {"D0", 1.0}, {"F", 0}};

    double sumA = 0, sumB = 0;

    cout.precision(6);

    for (int i = 0; i < 20; i++)
    {
        string a;
        double b;

        cin >> a >> b >> a;

        if (a == "P")
            continue;

        sumB += b;
        sumA += ma[a] * b;

    }

    cout << sumA/sumB;
    return 0;
}