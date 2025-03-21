#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

vector<int> alpha(26);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    sort(s.begin(), s.end());

    int res = 0;
    do
    {
        bool flag = true;
        for (int i = 1; i < s.length() - 1; i++)
        {
            if (s[i] == s[i - 1] || s[i] == s[i + 1])
            {
                flag = false;
                break;
            }
        }
        res += flag ? 1 : 0;
    } while (next_permutation(s.begin(), s.end()));

    cout << res;
    return 0;
}