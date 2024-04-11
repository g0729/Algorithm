#include <string>
#include <vector>

using namespace std;
int answer=0;
int n;
void dfs(int now,int sum,vector<int>&numbers,int&target){
    if(now==n){
        if(sum==target)
            answer++;
        return ;
    }
    
        dfs(now+1,sum+numbers[now],numbers,target);
        dfs(now+1,sum-numbers[now],numbers,target);
}
int solution(vector<int> numbers, int target) {
    
    n=numbers.size();
    dfs(0,0,numbers,target);
    return answer;
}