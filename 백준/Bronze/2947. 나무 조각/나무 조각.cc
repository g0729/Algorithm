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

    vector<int> v(5);
    for (int i = 0; i < 5; i++)
    {
        cin >> v[i];
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (v[j] > v[j + 1])
            {
                swap(v[j], v[j + 1]);
                for (int k = 0; k < 5; k++)
                {
                    cout << v[k] << " ";
                }
                cout << "\n";
            }
        }
    }

    return 0;
}