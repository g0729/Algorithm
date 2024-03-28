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
    char k;
    cin>>n>>k;
    if(k=='C')
    {
        for (int i = 0; i < n; i++)
        {
            char a;
            cin>>a;
            int b=a-'A'+1;
            cout<<b<<" ";
        }
        
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            int a;
            cin>>a;
            char b=a+'A'-1;
            cout<<b<<" ";
        }
        
    }
    cout<<endl;
}
return 0;
}