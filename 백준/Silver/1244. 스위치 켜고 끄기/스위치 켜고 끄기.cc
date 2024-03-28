#include <bits/stdc++.h>
using namespace std;

int Switch[101];

int main()
{
    int n;

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> Switch[i];
    }

    int t;

    cin >> t;

    while (t--)
    {
        int gender, num;
        cin >> gender >> num;

        if (gender == 1)
        {
            for (int i = num; i <= n; i += num)
            {
                Switch[i] = (Switch[i] + 1) % 2;
            }
        }
        else
        {
            int mid = num;
            Switch[mid] = (Switch[mid] + 1) % 2;
            int left = mid - 1;
            int right = mid + 1;
            while (1)
            {

                if (left <= 0 || right > n)
                    break;
                if (Switch[left] != Switch[right])
                    break;
                Switch[left] = (Switch[left] + 1) % 2;
                Switch[right] = Switch[left];
                left--;
                right++;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << Switch[i] << " ";
        if (i % 20 == 0)
            cout << "\n";
    }
}