#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long
bool RMAP[10][10];
bool CMAP[10][10];
int n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    string s;
    cin >> s;

    int x, y;
    x = y = 0;

    for (int i = 0; i < s.length(); i++)
    {
        int nx, ny;
        if (s[i] == 'U')
        {
            nx = x - 1;
            ny = y;
        }
        else if (s[i] == 'D')
        {
            nx = x + 1;
            ny = y;
        }
        else if (s[i] == 'R')
        {
            nx = x;
            ny = y + 1;
        }
        else
        {
            nx = x;
            ny = y - 1;
        }
        if(nx<0||ny<0||nx>=n||ny>=n)
        continue;

        if (s[i] == 'U'||s[i]=='D')
        {
            RMAP[x][y]=RMAP[nx][ny]=true;
        }
        else 
        {
            CMAP[x][y]=CMAP[nx][ny]=true;
        }
        x=nx;
        y=ny;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(CMAP[i][j]&&RMAP[i][j])
            cout<<"+";
            else if(CMAP[i][j]&&!RMAP[i][j])
            cout<<"-";
            else if(!CMAP[i][j]&&RMAP[i][j])
            cout<<"|";
            else
            cout<<".";
        }
        cout<<endl;
        
    }
    
    return 0;
}