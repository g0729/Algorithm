#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long
#define MAX 10000000

int n;
bool check(int num)
{
    if(num==0||num==1)
    return false;
    for (int i = 2; i*i <= num; i++)
    {
        if(num%i==0)
        return false;
    }
    
    return true;
}
void dfs(int now,int num)
{
    if(now==n)
    {
        cout<<num<<"\n";
        return;
    }

    for (int i = 0; i < 10; i++)
    {
        int next=num*10+i;

        if(check(next))
        {
            dfs(now+1,next);
        }
    }
    
}
int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;

    dfs(0,0);
    return 0;
}