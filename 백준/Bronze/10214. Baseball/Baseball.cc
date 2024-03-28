#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;

    while(t--)
    {
        int sum[2]={0};

        for (int i = 0; i < 9; i++)
        {
            int a,b;
            cin>>a>>b;
            sum[0]+=a;
            sum[1]+=b;
        }
        
        if(sum[0]>sum[1])
        cout<<"Yonsei\n";
        else if(sum[0]<sum[1])
        cout<<"Korea\n";
        else
        cout<<"Draw\n";
    }
    return 0;
}