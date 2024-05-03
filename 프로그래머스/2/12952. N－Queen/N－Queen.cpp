#include <string>
#include <vector>

using namespace std;
int answer;
int len;
vector<int>arr;

bool check(int now){
    for(int i = 0 ; i<now;i++){
        if(arr[i]==arr[now])
            return false;
        if(abs(arr[i]-arr[now])==(now-i))
            return false;
    }
    return true;
}
void dfs(int now){
    if (now==len){
        answer++;
        return;
    }
    for(int i = 0 ; i<len;i++){
        arr.push_back(i);
        if(check(now))
            dfs(now+1);
        arr.pop_back();
    }
}

int solution(int n) {
    
    len =n;
    dfs(0);
    return answer;
}