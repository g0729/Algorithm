#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> se;

    for (int i = 1;; i++)
    {
        int temp = i * (i + 1) / 2;
        if (temp > 1000)
            break;
        se.insert(temp);
    }

    int t;
    cin >> t;

    while (t--)
    {
        int k;
        cin >> k;
        bool check = false;
        for (int i = 1; i <= k-2; i++)
        {
            for (int j = 1; j < k - i; j++)
            {
                if (se.find(i) != se.end() && se.find(j) != se.end() && se.find(k - i - j) != se.end())
                {
                    cout << "1\n";
                    check = true;
                    break;
                }
            }
            if (check)
                break;
        }
        if(!check)
        cout << "0\n";
    }
}