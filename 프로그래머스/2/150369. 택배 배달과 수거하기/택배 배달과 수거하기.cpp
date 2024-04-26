#include <string>
#include <vector>

using namespace std;
long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups)
{
    long long answer = 0;
    int idx1 = n - 1, idx2 = n - 1;
    while (1)
    {
        while (idx1 >= 0 && deliveries[idx1] == 0)
            idx1--;
        while (idx2 >= 0 && pickups[idx2] == 0)
            idx2--;

        if (idx1 == -1 && idx2 == -1)
            break;
        answer += (max(idx1, idx2) + 1) * 2;
        int sum = 0;
        while (idx1 >= 0)
        {
            sum += deliveries[idx1];
            if (sum >= cap)
            {
                if (sum == cap)
                    idx1--;
                else
                    deliveries[idx1] = sum - cap;
                break;
            }
            idx1--;
        }
        sum = 0;
        while (idx2 >= 0)
        {
            sum += pickups[idx2];
            if (sum >= cap)
            {
                if (sum == cap)
                    idx2--;
                else
                    pickups[idx2] = sum-cap;
                break;
            }
            idx2--;
        }
    }
    return answer;
}