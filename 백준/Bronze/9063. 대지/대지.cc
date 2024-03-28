#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long
#define MOD 1000000007

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int minX, minY, maxX, maxY;

    minX=minY=1e9;
    maxX=maxY=-1e9;
    
    int n;
    cin>>n;

    for (int i = 0; i < n; i++)
    {
        int a,b;
        cin>>a>>b;

        minX=min(minX,a);
        minY=min(minY,b);
        maxX=max(maxX,a);
        maxY=max(maxY,b);
    }
    
    cout<<(maxX-minX)*(maxY-minY);

    return 0;
}