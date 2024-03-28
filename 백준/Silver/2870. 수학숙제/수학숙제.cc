#include <bits/stdc++.h>
using namespace std;
bool cmp(string a, string b)
{
    if (a.length() == b.length())
    {
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] == b[i])
                continue;
            return a[i] < b[i];
        }
    }
    return a.length() < b.length();
}
int main()
{
    int n;
    cin >> n;
    vector<string> res;
    for (int i = 0; i < n; i++)
    {
        string s, temp;
        cin >> s;
        for (int j = 0; j < s.length(); j++)
        {
            if (s[j] >= '0' && s[j] <= '9')
            {
                temp += s[j];
            }
            if (s[j] < '0' || s[j] > '9' || j == s.length() - 1)
            {

                if (!temp.empty())
                {
                    res.push_back(temp);
                    temp.clear();
                }
            }
        }
    }
    vector<string> ans;
    for (int i = 0; i < res.size(); i++)
    {
        bool check = false;
        string temp;
        for (int j = 0; j < res[i].length(); j++)
        {
            if (res[i][j] == '0' && !check)
            {
                continue;
            }
            check = true;
            temp += res[i][j];
        }
        if (!check)
            ans.push_back("0");
        else
            ans.push_back(temp);
    }

    sort(ans.begin(), ans.end(), cmp);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "\n";
    }
}