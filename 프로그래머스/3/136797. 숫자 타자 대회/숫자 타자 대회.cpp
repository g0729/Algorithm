#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int cal(int &now, int &target)
{
    pair<int, int> src, dst;
    if (now == target)
        return 1;
    if (now == 0)
        src = {4, 2};
    else
        src = {(now - 1) / 3 + 1, (now - 1) % 3 + 1};
    if (target == 0)
        dst = {4, 2};
    else
        dst = {(target - 1) / 3 + 1, (target - 1) % 3 + 1};

    pair<int, int> diff = {abs(dst.first - src.first), abs(dst.second - src.second)};

    return min(diff.first, diff.second) * 3 + abs(diff.first - diff.second) * 2;
}
pair<int, int> sort(int a, int b)
{
    if (a <= b)
        return {a, b};
    else
        return {b, a};
}
int solution(string numbers)
{
    int answer = 0;

    vector<vector<vector<int>>> dp(numbers.size() + 1, vector<vector<int>>(10, vector<int>(10, -1)));

    dp[0][4][6] = 0;

    for (int i = 1; i <= numbers.size(); i++)
    {
        int target = numbers[i - 1] - '0';

        for (int j = 0; j < 9; j++)
        {
            for (int k = j + 1; k < 10; k++)
            {
                if (dp[i - 1][j][k] == -1)
                    continue;

                int weightA, weightB;
                weightA = cal(j, target);
                weightB = cal(k, target);

                pair<int, int> temp = sort(target, k);
                if (dp[i][temp.first][temp.second] == -1)
                    dp[i][temp.first][temp.second] = dp[i - 1][j][k] + weightA;
                else
                    dp[i][temp.first][temp.second] = min(dp[i][temp.first][temp.second], dp[i - 1][j][k] + weightA);

                temp = sort(j, target);
                if (dp[i][temp.first][temp.second] == -1)
                    dp[i][temp.first][temp.second] = dp[i - 1][j][k] + weightB;
                else
                    dp[i][temp.first][temp.second] = min(dp[i][temp.first][temp.second], dp[i - 1][j][k] + weightB);
            }
        }
    }
    answer = 1e9;
    for (int i = 0; i < 9; i++)
    {
        for (int j = i + 1; j < 10; j++)
        {
            if (dp[numbers.size()][i][j] == -1)
                continue;
            answer = min(answer, dp[numbers.size()][i][j]);
        }
    }
    return answer;
}
