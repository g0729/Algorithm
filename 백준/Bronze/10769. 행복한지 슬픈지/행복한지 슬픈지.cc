#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    getline(cin, s);

    int happy, sad;
    happy = sad = 0;

    int now = 0;

    while (s.find(":-)", now) != string::npos)
    {
        happy++;
        now += s.find(":-)", now) + 3;
    }

    now = 0;

    while (s.find(":-(", now) != string::npos)
    {
        sad++;
        now += s.find(":-(", now) + 3;
    }

    if (happy == 0 && sad == 0)
        cout << "none";
    else if (happy > sad)
        cout << "happy";
    else if (happy < sad)
        cout << "sad";
    else
        cout << "unsure";
    return 0;
}