#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q;
    vector<int> v;
    cin >> q;
    while (q--)
    {
        int op, a;
        cin >> op;
        if (op == 1)
        {
            cin >> a;
            v.push_back(a);
        }
        else if (op == 2)
        {
            int left = 0, right = 0;
            for (int i = 0; i < v.size(); i++)
            {
                if (i < v.size() / 2)
                    left += v[i];
                else
                    right += v[i];
            }

            if (left <= right)
                v.erase(v.begin(), v.begin() + v.size() / 2);
            else
                v.erase(v.begin() + v.size() / 2, v.end());
            cout << min(left, right) << "\n";
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}