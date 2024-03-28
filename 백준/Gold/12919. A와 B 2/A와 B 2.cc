#include <bits/stdc++.h>
using namespace std;
string a, b;
bool check;
void dfs(string now)
{
    string temp;
    if (now == a)
    {
        cout << "1";
        exit(0);
    }
    if (now.length() <= a.length())
        return;
    if (now.back() == 'A')
    {
        temp = now;
        temp.pop_back();
        dfs(temp);
    }
    temp = now;
    if (now[0] == 'B')
    {
        reverse(temp.begin(), temp.end());
        temp.pop_back();
        dfs(temp);
    }
}
int main()
{
    cin >> a >> b;
    dfs(b);
    cout << "0";
}