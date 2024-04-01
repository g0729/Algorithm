#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    vector<int>cnt(10);
    for(int it:numbers)
        cnt[it]++;
    for(int i= 0;i<10;i++)
        if(!cnt[i])
            answer+=i;
    return answer;
}