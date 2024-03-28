#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> v;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            v.push_back(i);
    }
    if (k > v.size())
        cout << "0";
    else
        cout << v[k - 1];
}