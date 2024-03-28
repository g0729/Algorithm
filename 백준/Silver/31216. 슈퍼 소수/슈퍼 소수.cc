#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 350000
#define INF 987654321
vector<int> v;
bool isPrime[MAX + 1];
void era()
{
    for (int i = 2; i * i <= MAX; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= MAX; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i <= MAX; i++)
    {
        if (isPrime[i])
            v.push_back(i);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(isPrime, true, sizeof(isPrime));
    era();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << v[v[n - 1] - 1] << "\n";
    }

    return 0;
}