#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[101];
    while (1)
    {
        memset(arr, 0, sizeof(arr));
        vector<int>v;
        int res=0;
        while (1)
        {
            int a;
            cin >> a;
            if (a == -1)
                return 0;
            if (a == 0)
                break;
            arr[a]++;
            v.push_back(a);
        }
        for (int i = 0; i < v.size(); i++)
        {
            int now=v[i]*2;
            if(now>100)
            continue;
            res+=arr[now];
        }
        cout<<res<<"\n";
    }
}