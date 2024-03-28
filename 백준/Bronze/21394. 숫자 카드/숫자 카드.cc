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

    int t;
    cin >> t;
    while (t--)
    {
        vector<int> v;
        int sum = 0;
        for (int i = 1; i <= 9; i++)
        {
            int a;
            cin >> a;
            sum += a;
            for (int j = 0; j < a; j++)
            {
                if (i == 6)
                    v.push_back(9);
                else
                    v.push_back(i);
            }
        }

        sort(v.begin(), v.end(), greater<int>());

        int left = 0;
        int right = sum - 1;

        vector<int> res(sum);

        for (int i = 0; i < sum; i++)
        {
            if (i % 2 == 0)
            {
                res[left] = v[i];
                left++;
            }
            else
            {
                res[right] = v[i];
                right--;
            }
        }
        for (int i = 0; i < sum; i++)
        {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}