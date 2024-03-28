#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    pair<int, int> king;
    pair<int, int> stone;

    string s;
    cin >> s;

    king.first = s[0] - 'A' + 1;
    king.second = s[1] - '0';

    cin >> s;

    stone.first = s[0] - 'A' + 1;
    stone.second = s[1] - '0';

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> s;
        pair<int, int> next = king;

        if (s == "R")
            next.first += 1;
        else if (s == "L")
            next.first -= 1;
        else if (s == "B")
            next.second -= 1;
        else if (s == "T")
            next.second += 1;
        else if (s == "RT")
        {
            next.first += 1;
            next.second += 1;
        }
        else if (s == "LT")
        {
            next.first -= 1;
            next.second += 1;
        }
        else if (s == "RB")
        {
            next.first += 1;
            next.second -= 1;
        }
        else
        {
            next.first -= 1;
            next.second -= 1;
        }
        if (next.first <= 0 || next.first > 8 || next.second <= 0 || next.second > 8)
        {
            continue;
        }
        if (next.first == stone.first && next.second == stone.second)
        {
            pair<int, int> stone_next = stone;
            stone_next.first = stone_next.first + (next.first - king.first);
            stone_next.second = stone_next.second + (next.second - king.second);
            if (stone_next.first <= 0 || stone_next.first > 8 || stone_next.second <= 0 || stone_next.second > 8)
            {
                continue;
            }
            stone = stone_next;
        }
        king = next;
    }
    char temp = king.first + 'A' - 1;
    cout << temp << king.second << endl;
    temp = (char)stone.first + 'A' - 1;
    cout << temp << stone.second;
}