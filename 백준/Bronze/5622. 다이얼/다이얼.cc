#include <iostream>

using namespace std;

int main()
{
    int usingTime[26] = {3, 3, 3,
                         4, 4, 4,
                         5, 5, 5,
                         6, 6, 6,
                         7, 7, 7, 8,
                         8, 8, 8,
                         9, 9, 9,
                         10, 10, 10, 10};
    char input[16] = {0};
    int idx = 0;
    while (true)
    {
        input[idx] = cin.get();
        if (input[idx] == '\n')
            break;
        idx++;
    }

    int sum = 0;
    for (int i = 0; i < idx; i++)
    {
        sum += usingTime[input[i] - 'A'];
    }
    cout << sum;
}