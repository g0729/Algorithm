#include <iostream>
#include <vector>
using namespace std;
vector<pair<int, int>> v;
short arr[9][9];
int o_cnt = 0;
void print()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << arr[j][i];
        }
        cout << endl;
    }
}
bool check(int x, int y)
{
    int ta = arr[x][y];
    for (int i = 0; i < 9; i++)
    {
        if (i != x && arr[i][y] == ta)
            return false;
        if (i != y && arr[x][i] == ta)
            return false;
    }
    for (int j = (y / 3) * 3; j < (y / 3) * 3 + 3; j++)
        for (int i = (x / 3) * 3; i < (x / 3) * 3 + 3; i++)
            if (j != y && i != x && arr[i][j] == ta)
                return false;
    return true;
}
void DFS(int n)
{
    if (n == o_cnt)
    {
        print();
        exit(0);
    }
    for (int i = 1; i <= 9; i++)
    {
        arr[v[n].first][v[n].second] = i;
        if (check(v[n].first, v[n].second))
        {
            DFS(n + 1);
        }
    }
    arr[v[n].first][v[n].second] = 0;
    return;
}
int main()
{
    string s;
    for (int y = 0; y < 9; y++)
    {
        cin>>s;
        for (int x = 0; x < 9; x++)
        {
            arr[x][y]=s[x]-'0';
            if (arr[x][y] == 0)
            {
                v.push_back({x, y});
                o_cnt++;
            }
        }
    }
    DFS(0);
}