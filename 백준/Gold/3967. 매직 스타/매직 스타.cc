#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
vector<char> v;
vector<vector<int>> check_list = {{0, 2, 5, 7}, {0, 3, 6, 10}, {7, 8, 9, 10}, {1, 2, 3, 4}, {1, 5, 8, 11}, {4, 6, 9, 11}};
bool isUsed[12];
bool flag = false;
bool check()
{
    for (int i = 0; i < check_list.size(); i++)
    {
        int sum = 0;
        for (int j = 0; j < check_list[i].size(); j++)
            sum += v[check_list[i][j]] - 'A' + 1;
        if (sum != 26)
            return false;
    }

    return true;
}
void print_ans()
{
    cout << "...." << v[0] << "....\n"
         << "." << v[1] << "." << v[2] << "." << v[3] << "." << v[4] << ".\n"
         << ".." << v[5] << "..." << v[6] << "..\n"
         << "." << v[7] << "." << v[8] << "." << v[9] << "." << v[10] << ".\n"
         << "...." << v[11] << "....\n";
}
void dfs(int cnt)
{
    if (cnt == 12)
    {
        if (check())
        {
            print_ans();
            flag = true;
        }
        return;
    }

    if (v[cnt] != 'x')
        dfs(cnt + 1);
    else
    {
        for (int i = 0; i < 12; i++)
        {
            if (isUsed[i])
                continue;
            isUsed[i] = true;
            v[cnt] = 'A' + i;
            dfs(cnt + 1);
            if (flag)
                return;
            isUsed[i] = false;
            v[cnt] = 'x';
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    for (int i = 0; i < 5; i++)
    {
        cin >> s;
        for (int j = 0; j < s.length(); j++)
        {
            if (s[j] != '.')
            {
                v.push_back(s[j]);
                if (s[j] != 'x')
                    isUsed[s[j] - 'A'] = true;
            }
        }
    }

    dfs(0);
    return 0;
}