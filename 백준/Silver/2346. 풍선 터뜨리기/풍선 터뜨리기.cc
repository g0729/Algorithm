#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[1001];
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    deque<int> dq;
    for (int i = 1; i <= n; i++)
    {
        dq.push_back(i);
    }
    int now;
    while (1)
    {
        now = dq.front();
        cout << dq.front() << " ";
        dq.pop_front();
        if (arr[now] < 0)
        {
            for (int i = 0; i < abs(arr[now]) ; i++)
            {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
        else
        {
            for (int i = 0; i < arr[now] - 1; i++)
            {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        if (dq.empty())
            break;
    }
}