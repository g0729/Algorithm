#include<bits/stdc++.h>
using namespace std;
#define MAX 987654321
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
        int n;
        cin>>n;

        int Max=0;
        string MAX_NAME;

        for (int i = 0; i < n; i++)
        {
            int a;
            string name;
            cin>>a>>name;

            if(a>Max)
            {
                Max=a;
                MAX_NAME=name;
            }
        }
        cout<<MAX_NAME<<"\n";
    }
return 0;
}