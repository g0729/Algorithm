#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    lint t;
    cin>>t;

    while(t--)
    {
        lint arr[100][3];
        lint m;
        cin>>m;
        for (lint i = 0; i < m; i++)
        {
            for (lint j = 0; j < 3; j++)
            {
                cin>>arr[i][j];
            }
        }
        
        lint k,d,a;

        cin>>k>>d>>a;

        lint res=0;

        for (lint i = 0; i < m; i++)
        {
            lint temp;

            temp=k*arr[i][0]-d*arr[i][1]+a*arr[i][2];

            if(temp<0)
            continue;

            res+=temp;
        }
        
        cout<<res<<"\n";
    }
    return 0;
}