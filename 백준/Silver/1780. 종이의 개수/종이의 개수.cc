#include <bits/stdc++.h>
using namespace std;
#define MAX 2500
int MAP[MAX][MAX];
int cnt[3];
int n;
void dfs(int x, int y, int size)
{
    bool mi, ze, on;
    mi = ze = on = true;
    for (int i = x; i < x + size; i++)
    {
        for (int q = y; q < y + size; q++)
        {
            if (MAP[i][q] == -1)
            {
                ze = on = false;
            }
            if (MAP[i][q] == 0)
            {
                mi = on = false;
            }
            if (MAP[i][q] == 1)
            {
                mi = ze = false;
            }
            if (!mi && !ze && !on)
                break;
        }
    }
    if (mi)
    {
        cnt[0]++;
        return;
    }
    if (ze)
    {
        cnt[1]++;
        return;
    }
    if (on)
    {
        cnt[2]++;
        return;
    }
    dfs(x,y,size/3);
    dfs(x+size/3,y,size/3);
    dfs(x+2*size/3,y,size/3);
    dfs(x,y+size/3,size/3);
    dfs(x+size/3,y+size/3,size/3);
    dfs(x+2*size/3,y+size/3,size/3);
    dfs(x,y+2*size/3,size/3);
    dfs(x+size/3,y+2*size/3,size/3);
    dfs(x+2*size/3,y+2*size/3,size/3);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int q = 0; q < n; q++)
        {
            cin >> MAP[i][q];
        }
    }
    dfs(0,0,n);
    for (int i = 0; i < 3; i++)
    {
        cout<<cnt[i]<<endl;
    }
    
}