#include <string>
#include <vector>
#include <memory.h>
#include<algorithm>
#include <iostream>

using namespace std;
vector<int>v;

int cal(int num){
    vector<int>temp;
    for(int i=2;i*i<=num;i++){
        int cnt=0;
        while(num%i==0){
            cnt++;
            num/=i;
        }
        temp.push_back(cnt);
    }
    if(num!=1)
        temp.push_back(1);
    int res=1;
    for(int i=0;i<temp.size();i++){
        res*=temp[i]+1;
    }
    return res;
}
vector<int> solution(int e, vector<int> starts) {
    vector<int> answer;
    v.push_back(0);
    for(int i =1 ; i<=e;i++){
        v.push_back(cal(i));
    }
    
    vector<int>res(e+1);
    int max,max_idx;
    max=0;
    for(int i=e ;i>=1;i--){
        if(v[i]>=max){
            max=v[i];
            max_idx=i;
        }
        res[i]=max_idx;
    }
    for(int i =0;i<starts.size();i++){
        answer.push_back(res[starts[i]]);
    }
    return answer;
}