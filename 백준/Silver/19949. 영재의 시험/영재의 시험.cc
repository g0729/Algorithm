#include <bits/stdc++.h>
using namespace std;
#define MAX 987654321

int arr[11];
int res;
void dfs(int idx, int pre, int ppre, int cnt)
{
    if (idx == 11)
    {
        if (cnt >= 5)
            res++;
        return ;
    }

    for(int i =1 ; i<=5;i++)
    {
        if(pre==ppre)
        {
            if(i==pre)
            continue;
        }

        if(arr[idx]==i)
        {
            dfs(idx+1,ppre,i,cnt+1);
        }
        else
        {
            dfs(idx+1,ppre,i,cnt);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 1; i <= 10; i++)
    {
        cin >> arr[i];
    }

    dfs(1,0,0,0);

    cout<<res;
    return 0;
}