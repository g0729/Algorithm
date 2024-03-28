#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long
bool MAP[6][6];
    int dx[8] = {-1,-2,-2,-1,1,2,2,1};
    int dy[8] = {-2,-1,1,2,-2,-1,1,2};
int toNum(char c)
{
    if (c >= '1' && c <= '9')
        return c - '1';
    else
        return c - 'A';
}
bool check(int x1, int y1, int x2, int y2)
{

    for (int i = 0; i < 8; i++)
    {
        int nx = x1 + dx[i];
        int ny = y1 + dy[i];

        if (nx < 0 || ny < 0 || nx >= 6 || ny >= 6)
            continue;

        if (nx == x2 && ny == y2)
            return true;
    }

    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string now;
    cin >> now;

    pair<int, int> start;

    start.first = toNum(now[0]);
    start.second = toNum(now[1]);
    bool flag = true;

    MAP[start.first][start.second] = true;
    string s;

    for (int i = 0; i < 35; i++)
    {
        cin >> s;

        int x1, y1, x2, y2;

        x1 = toNum(now[0]);
        y1 = toNum(now[1]);
        x2 = toNum(s[0]);
        y2 = toNum(s[1]);

        if (!check(x1, y1, x2, y2) )
        {
            flag = false;
        }
        if(MAP[x2][y2])
        {
            flag=false;
        }
        MAP[x2][y2] = true;
        now = s;
    }


    pair<int, int> end;
    end.first = toNum(s[0]);
    end.second = toNum(s[1]);


    if (!check(end.first, end.second, start.first, start.second))
        flag = false;
    
    if (flag)
        cout << "Valid";
    else
        cout << "Invalid";

    return 0;
}