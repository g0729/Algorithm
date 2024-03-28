#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    lint arr[6];
    lint carr[6];

    int t;
    cin >> t;
    while ((t--))
    {
        lint n;
        cin >> n;
        int res = 1;
        lint sum = 0;
        for (int i = 0; i < 6; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }
        if(sum>n)
        {
            cout<<res<<"\n";
            continue;
        }
        while (1)
        {

            sum=0;
            for (int i = 0; i < 6; i++)
            {
                carr[i] = arr[i] + arr[(i + 3) % 6] + arr[i - 1 == -1 ? 5 : i - 1] + arr[i + 1 == 6 ? 0 : i + 1];
                sum += carr[i];
            }

            for (int i = 0; i < 6; i++)
            {
                arr[i] = carr[i];
            }

            res++;
            if (n < sum)
            {
                cout << res << "\n";
                break;
            }
        }
    }

    return 0;
}