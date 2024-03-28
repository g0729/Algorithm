#include <bits/stdc++.h>
using namespace std;
#define MAX 300 * 300 * 300
#define lint long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int p1,p2,p3,x1,x2,x3;
    cin>>p1>>p2>>p3>>x1>>x2>>x3;

    for (int i = 1; i < MAX; i++)
    {
        if(i%p1==x1&&i%p2==x2&&i%p3==x3)
        {
            cout<<i;
            return 0;
        }
    }
    
    cout<<"-1";
    return 0;
}