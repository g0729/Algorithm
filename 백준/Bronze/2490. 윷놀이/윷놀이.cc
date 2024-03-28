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

    for (int t = 0; t < 3; t++)
    {

        int cnt = 0;

        for (int i = 0; i < 4; i++)
        {
            int a;
            cin >> a;

            if (a == 0)
                cnt++;
        }

        if (cnt == 0)
            cout<<"E";
        else if(cnt==1)
            cout<<"A";
        else if(cnt==2)
            cout<<"B";
        else if(cnt==3)
            cout<<"C";
        else
            cout<<"D";
        cout<<endl;
    }
    return 0;
}