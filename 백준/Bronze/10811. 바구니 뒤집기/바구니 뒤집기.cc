#include <bits/stdc++.h>
using namespace std;
#define MAX 987654321
#define lint long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int>v(n+1);

    for (int i = 1; i <= n; i++)
    {
        v[i]=i;
    }
    
    for (int i = 0; i < m; i++)
    {
        int a,b;
        cin>>a>>b;

        for (int j = 0; j < (b-a+1)/2; j++)
        {
            int temp=v[a+j];
            v[a+j]=v[b-j];
            v[b-j]=temp;
        }
        
    }
    
    for (int i = 1; i <= n; i++)
    {
        cout<<v[i]<<" ";
    }
    
    return 0;
}