#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;

    int answer = 1e9;
    for (int i = 0; i < 2; i++)
    {
        char color;
        if (i == 0)
            color = 'R';
        else
            color = 'B';
        int start;
        for (start = 0; start < s.length(); start++)
        {
            if (s[start] != color)
                break;
        }
        int cnt = 0;
        for (int j = start; j < s.length(); j++)
        {
            if (s[j] == color)
                cnt += 1;
        }
        answer = min(answer, cnt);
        for (start = s.length() - 1; start >= 0; start--)
        {
            if (s[start] != color)
                break;
        }
        cnt = 0;
        for (int j = start; j >= 0; j--)
        {
            if (s[j] == color)
                cnt += 1;
        }
        answer = min(answer, cnt);
    }
    cout << answer;
    return 0;
}