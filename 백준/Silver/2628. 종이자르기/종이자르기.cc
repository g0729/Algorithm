#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int>row,column;

    int k;
    cin>>k;

    for (int i = 0; i < k; i++)
    {
        int a,b;
        cin>>a>>b;
        if(a==0)
            row.push_back(b);
        else
            column.push_back(b);
    }
    row.push_back(0);
    row.push_back(m);
    column.push_back(0);
    column.push_back(n);
    
    sort(row.begin(),row.end());
    sort(column.begin(),column.end());

    int MaxRow,MaxCol;
    MaxRow=MaxCol=0;
    for (int i = 1; i < row.size(); i++)
    {
        MaxRow=max(MaxRow,row[i]-row[i-1]);
    }
    
    for (int i = 1; i < column.size(); i++)
    {
        MaxCol=max(MaxCol,column[i]-column[i-1]);
    }
    
    cout<<MaxRow*MaxCol;
    return 0;
}