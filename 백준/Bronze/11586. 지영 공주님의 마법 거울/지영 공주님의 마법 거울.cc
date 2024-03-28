#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<string> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int a;
    cin >> a;

    if (a == 2)
    {
        for (int i = 0; i < n; i++)
            reverse(v[i].begin(), v[i].end());
    }
    if(a==3)
    {
        for (int i = 0; i < n/2; i++)
        {
            swap(v[i],v[n-i-1]);
        }
        
    }

    for (int i = 0; i < n; i++)
    {
        cout<<v[i]<<"\n";
    }
    
    return 0;
}