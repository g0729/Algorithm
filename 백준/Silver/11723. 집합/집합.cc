#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long
bool arr[21];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m;
    cin >> m;

    string cmd;
    int num;
    while (m--)
    {
        cin >> cmd;

        if (cmd == "add")
        {
            cin >> num;
            arr[num] = true;
        }
        else if (cmd == "remove")
        {
            cin >> num;
            arr[num] = false;
        }
        else if (cmd == "check")
        {
            cin >> num;
            cout << arr[num] << "\n";
        }
        else if (cmd == "toggle")
        {
            cin >> num;
            if (arr[num])
                arr[num] = false;
            else
                arr[num] = true;
        }
        else if (cmd == "all")
        {
            for (int i = 1; i <= 20; i++)
            {
                arr[i] = true;
            }
        }
        else
        {
            for (int i = 1; i <= 20; i++)
            {
                arr[i] = false;
            }
        }
    }
    return 0;
}