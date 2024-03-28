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
    vector<char> v = {'S', 'N', 'U'};

    char res;
    double sum = 0;

    for (int i = 0; i < 3; i++)
    {
        int a, b;
        cin >> a >> b;

        double temp = a * 10;

        if (temp >= 5000)
            temp -= 500;

        temp = (b * 10) / temp;

        if (sum < temp)
        {
            sum = temp;
            res = v[i];
        }
    }

    cout << res;
    return 0;
}