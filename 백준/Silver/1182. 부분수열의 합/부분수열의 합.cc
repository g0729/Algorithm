#include <bits/stdc++.h>
using namespace std;
int arr[20];
int n, s;
int cnt;
void dfs(int now, int sum)
{
    if (now == n)
    {
        if (sum == s)
            cnt++;
        return ;
    }
    dfs(now+1,sum);
    dfs(now+1,sum+arr[now]);
}
int main()
{
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    dfs(0,0);
    if(s==0)
    cnt--;
    cout<<cnt;
}