#include <bits/stdc++.h>
using namespace std;

int MAP[40][40];
int res[40][40];
int main()
{
    int r, c;

    cin >> r >> c;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> MAP[i][j];
        }
    }

    for (int i = 0; i  <= r-3; i++)
    {
        for (int j = 0; j  <= c-3; j++)
        {
            vector<int> temp;
            for (int k = i; k < i + 3; k++)
            {
                for (int m = j; m < j + 3; m++)
                {
                    temp.push_back(MAP[k][m]);
                }
            }

            sort(temp.begin(), temp.end());
            res[i][j] = temp[4];
        }
    }
    int t;
    int ans=0;
    cin>>t;
    for (int i = 0; i  <= r-3; i++)
    {
        for (int j = 0; j <= c-3; j++)
        {
            if(res[i][j]>=t)
            ans++;
        }
        
    }

    cout<<ans;
}