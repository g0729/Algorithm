#include <bits/stdc++.h>
using namespace std;
#define MAX 987654321
#define lint long long

struct Int
{
    int x1, x2, y1, y2;
};
int dx[] = {-1, 0};
int dy[] = {0, -1};
lint dp[101][101];
vector<Int> v;
int n, m, k;

bool operator == (const Int x,const Int y)
{
    if(x.x1==y.x1&&x.x2==y.x2&&x.y1==y.y1&&x.y2==y.y2)
    return true;
    else 
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 0; i < k; i++)
    {
        Int temp;
        cin >> temp.x1 >> temp.y1 >> temp.x2 >> temp.y2;
        v.push_back(temp);
    }
    dp[0][0]=1;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if(i==0&j==0)
            continue;
            for (int k = 0; k < 2; k++)
            {
                int x=i+dx[k];
                int y=j+dy[k];

                if(x<0||y<0)
                continue;;

                Int temp1,temp2;
                temp1.x1=i;
                temp1.x2=x;
                temp1.y1=j;
                temp1.y2=y;
                temp2.x1=x;
                temp2.x2=i;
                temp2.y1=y;
                temp2.y2=j;
                bool flag=false;
                for (int t = 0; t < v.size(); t++)
                {
                    Int temp3=v[t];
                    if(temp3==temp2||temp3==temp1)
                        {
                            flag=true;
                            break;
                        }
                }
                

                if(flag)
                continue;

                dp[i][j]+=dp[x][y];
            }
            
        }
        
    }
    
    cout<<dp[n][m];
    return 0;
}