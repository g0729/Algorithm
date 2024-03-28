#include <bits/stdc++.h>
using namespace std;
#define MAX 987654321
#define lint long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, l;
    cin >> n >> k >> l;
    vector<int> v;

    int cnt=0;
    for (int i = 0; i < n; i++)
    {

        int a, b, c;
        cin >> a >> b >> c;
        int sum = a + b + c;
        int MIN = min(a, b);
        MIN = min(MIN, c);

        if (MIN>=l&&sum>=k)
        {
            cnt++;
            v.push_back(a);
            v.push_back(b);
            v.push_back(c);
        }
    }

    cout<<cnt<<endl;

    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    
    return 0;
}