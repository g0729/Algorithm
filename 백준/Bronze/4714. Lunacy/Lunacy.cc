#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(2);
    double weight;
    while (1)
    {
        cin >> weight;
        if (weight == -1)
            break;
        cout << fixed;
        cout << "Objects weighing " << weight << " on Earth will weigh " << 0.167 * weight << " on the moon.\n";
    }
    return 0;
}