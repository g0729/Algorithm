#include <bits/stdc++.h>
using namespace std;

int main()
{
    char MAP[50][50];

    int n,m;

    cin>>n>>m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>MAP[i][j];
        }
    }
    
    int cntN,cntM;

    cntN=n;
    cntM=m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(MAP[i][j]=='X')
            {
                cntN--;
                break;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(MAP[j][i]=='X')
            {
                cntM--;
                break;
            }
        }
    }
    
    cout<<max(cntN,cntM);
    
}