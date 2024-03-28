#include <bits/stdc++.h>
using namespace std;
bool check[2001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> v[n];

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        for (int j = 0; j < temp; j++)
        {
            int a;
            cin >> a;
            v[i].push_back(a);
        }
    }

    for (int i = 0; i < n; i++)
    {
        memset(check,false,sizeof(check));
        for (int j = 0; j < n; j++)
        {
            if(j==i)
            continue;
            for (int k = 0; k < v[j].size(); k++)
            {
                check[v[j][k]]=true;
            }
        }
        bool flag=true;
        for (int j = 1; j <= m; j++)
        {
            if(!check[j])
            {
                flag=false;
                break;
            }
        }
        if(flag)
        {
            cout<<"1";
            return 0;
        }
    }
    cout<<"0";
}