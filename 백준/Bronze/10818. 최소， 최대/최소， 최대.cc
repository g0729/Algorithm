#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int MIN=1e7;
    int MAX=-1e7;
    int n;
    cin>>n;
    while(n--)
    {
        int a;
        cin>>a;
        MIN=min(MIN,a);
        MAX=max(MAX,a);
    }
    cout<<MIN<<" "<<MAX;
}