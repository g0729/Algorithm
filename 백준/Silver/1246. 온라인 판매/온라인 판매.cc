#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;

    cin >> n >> m;

    vector<int> v(m);

    for (int i = 0; i < m; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int start = max(0, m - n);

    int res_value = 0;
    int res_sum = 0;

    for (; start < m; start++)
    {
        int temp=v[start]*(m-start);
        if(temp>res_sum)
        {
            res_value=v[start];
            res_sum=temp;
        }
    }

    cout<<res_value<<" "<<res_sum;
}