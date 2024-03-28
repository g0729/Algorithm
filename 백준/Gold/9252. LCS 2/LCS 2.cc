#include<bits/stdc++.h>
using namespace std;
#define MAX 1001
int dp[MAX][MAX];
    string a,b;
void print(int x,int y)
{
    if(dp[x][y]==0)
    return;
    if(a[x-1]==b[y-1])
    {
        print(x-1,y-1);
        cout<<a[x-1];
    }
    else if(dp[x-1][y]>dp[x][y-1])
    {
        print(x-1,y);
    }
    else
    {
        print(x,y-1);
    }
}
int main()
{

    cin>>a>>b;

    for (int i = 1; i <= a.length(); i++)
    {
        for (int q = 1; q <= b.length(); q++)
        {
            if(a[i-1]==b[q-1])
            {
                dp[i][q]=dp[i-1][q-1]+1;
            }
            else
            {
                dp[i][q]=max(dp[i-1][q],dp[i][q-1]);
            }
        }
    }
    cout<<dp[a.length()][b.length()]<<endl;
    print(a.length(),b.length());

}