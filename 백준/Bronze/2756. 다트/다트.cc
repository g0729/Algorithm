#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321

int cal(double x, double y)
{
    double dis = sqrt(x * x + y * y);

    if (dis <= 3)
        return 100;
    else if (dis <= 6)
        return 80;
    else if (dis <= 9)
        return 60;
    else if (dis <= 12)
        return 40;
    else if (dis <= 15)
        return 20;
    else
        return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        double x, y;
        int p1, p2;
        p1 = p2 = 0;

        for (int i = 0; i < 3; i++)
        {
            cin >> x >> y;
            p1 += cal(x, y);
        }
        for (int i = 0; i < 3; i++)
        {
            cin >> x >> y;
            p2 += cal(x, y);
        }

        cout << "SCORE: " << p1 << " to " << p2 << ", ";
        if (p1 == p2)
            cout << "TIE.";
        else
        {
            cout << "PLAYER ";

            if (p1 > p2)
                cout << "1 ";
            else
                cout << "2 ";

            cout << "WINS.";
        }
        cout << "\n";
    }
    return 0;
}