#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    cin >> n;

    int arr[1000];

    int start, end;
    start = end = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int res = 0;
    
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            end = i;
        }
        else
        {
            res = max(res, arr[end] - arr[start]);
            start = end = i;
        }
    }

    res = max(res, arr[end] - arr[start]);

    cout << res;
}