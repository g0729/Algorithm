#include <bits/stdc++.h>
using namespace std;

set<int>se[10001];
int main()
{
    int n,m;

    cin>>n>>m;

    for (int i = 0; i < m; i++)
    {
        int a,b;
        cin>>a>>b;

        se[a].insert(b);
        se[b].insert(a);
    }
    
    int res=0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = i+1; j <= n; j++)
        {
            for (int k =j+1 ; k <= n; k++)
            {
                if(se[i].find(j)==se[i].end())
                {
                    if(se[i].find(k)==se[i].end())
                    {
                        if(se[j].find(k)==se[j].end())
                        res++;
                    }
                }
            }
        }
    }
    
    cout<<res;
}