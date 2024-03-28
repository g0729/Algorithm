#include <bits/stdc++.h>
using namespace std;
#define MAX 987654321
#define lint long long

bool checkArr[5][5] = {0};
int check(int x, int y)
{

    int res = 0;
    bool flag = true;
    for (int i = 0; i < 5; i++)
    {
        if (!checkArr[x][i])
        {
            flag = false;
            break;
        }
    }
    if (flag)
        res++;
    flag = true;

    for (int i = 0; i < 5; i++)
    {
        if (!checkArr[i][y])
        {
            flag = false;
            break;
        }
    }

    if (flag)
        res++;
    flag = true;

    if (x == y)
    {
        for (int i = 0; i < 5; i++)

            if (!checkArr[i][i])
            {
                flag = false;
                break;
            }
    }
    else
    {
        flag=false;
    }
    if (flag)
        res++;
    flag = true;
    if (x + y == 4)
    {
        for (int i = 0; i < 5; i++)
        {
            if (!checkArr[i][4-i])
            {
                flag = false;
                break;
            }
        }
    }
    else
    {
        flag = false;
    }
    if (flag)
        res++;

    return res;
}
int main()
{

    int arr[5][5];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> arr[i][j];
        }
    }

    int sum = 0;
    for (int i = 1; i <= 25; i++)
    {
        int a;
        cin >> a;
        bool flag=true;
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                if (arr[j][k] == a)
                {
                    checkArr[j][k] = true;
                    sum += check(j, k);
                    if (sum >= 3)
                    {
                        cout << i;
                        return 0;
                    }
                    flag=false;
                    break;
                }
            }
            if(!flag)
            break;
        }
    }

    return 0;
}