#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321

int main()
{

    string s;
    getline(cin, s);

    int a, b;
    a = b = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'H' || s[i] == 'A' || s[i] == 'P' || s[i] == 'Y')
            a++;
        if (s[i] == 'S' || s[i] == 'A' || s[i] == 'D')
            b++;
    }

    if (a == 0 && b == 0)
    {
        cout << "50.00";
        return 0;
    }

    double temp = ((double)a / (double)(a + b)) * 100;

    printf("%.2f", round(temp * 100) / 100);
    return 0;
}