#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<char>v;
vector<char>lis={'A','C','F','J','M','N','R','T'};
vector<bool>visited(8,false);
int answer;
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

bool check(vector<string>&data){
    int idx1,idx2;
    for(int i = 0 ; i<data.size();i++){
        for(int j=0;j<8;j++)
            if(v[j]==data[i][0])
                idx1=j;
        for(int j = 0 ; j<8;j++)
            if(v[j]==data[i][2])
                idx2=j;
        char op=data[i][3];
        int num=data[i][4]-'0';

        int diff=abs(idx1-idx2)-1;
        if(op=='>'){
            if(diff<=num)
                return false;
        }
        if(op=='<'){
            if(diff>=num)
                return false;
        }
        if(op=='='){
            if(diff!=num)
                return false;
        }
    }

    return true;
}
void dfs(int cnt,vector<string>&data){
    if(cnt==8){
        if(check(data))
            answer++;
        return;
    }

    for(int i= 0 ; i<8;i++){
        if(visited[i])
            continue;
        v.push_back(lis[i]);
        visited[i]=true;
        dfs(cnt+1,data);
        v.pop_back();
        visited[i]=false;
    }
}
int solution(int n, vector<string> data) {
    answer = 0;
    dfs(0,data);
    return answer;
}