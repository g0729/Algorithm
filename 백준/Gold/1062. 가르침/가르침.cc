#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int n, k;
vector<string> words;
bool isSelected[26];
int res = 0;
void dfs(int start, int num)
{
    if (num == k)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            string temp = words[i];
            bool flag = true;
            for (int j = 0; j < temp.length(); j++)
            {
                if (!isSelected[temp[j] - 'a'])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                cnt++;
        }

        res = max(res, cnt);
        return;
    }

    for (int i = start; i < 26; i++)
    {
        if (!isSelected[i])
        {
            isSelected[i] = true;
            dfs(i, num + 1);
            isSelected[i] = false;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    if (k < 5)
    {
        cout << "0";
        return 0;
    }
    k -= 5;
    isSelected[0] = isSelected['n' - 'a'] = isSelected['t' - 'a'] = isSelected['i' - 'a'] = isSelected['c' - 'a'] = true;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        s = s.substr(4, s.length() - 8);
        words.push_back(s);
    }

    dfs(0, 0);

    cout << res;
    return 0;
}