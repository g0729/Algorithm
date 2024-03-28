#include <bits/stdc++.h>
using namespace std;
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
    int idx = 1;
    vector<string> v = {"", "Yakk", "Doh", "Seh", "Ghar", "Bang", "Sheesh"};
    while (t--)
    {
        int arr[2];

        cin >> arr[0] >> arr[1];

        sort(arr, arr + 2, greater<int>());

        cout << "Case " << idx << ": ";
        if (arr[0] == arr[1])
        {
            switch (arr[0])
            {
            case 1:
                cout << "Habb Yakk";
                break;
            case 2:
                cout << "Dobara";
                break;
            case 3:
                cout << "Dousa";
                break;
            case 4:
                cout << "Dorgy";
                break;
            case 5:
                cout << "Dabash";
                break;
            case 6:
                cout << "Dosh";
                break;
            }
        }
        else if (arr[0] == 6 && arr[1] == 5)
            cout << "Sheesh Beesh";
        else
            cout << v[arr[0]] << " " << v[arr[1]];
        cout << "\n";
        idx++;
    }
    return 0;
}