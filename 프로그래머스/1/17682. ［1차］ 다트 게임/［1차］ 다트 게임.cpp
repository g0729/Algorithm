#include <string>
#include <vector>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int>v;
    
    int idx=0;
    int n=dartResult.length();
    
    while(idx<n){
        int num;
        if(dartResult[idx]=='1' &&dartResult[idx+1]=='0'){
            idx+=2;
            num=10;
        }
        else{
            num=dartResult[idx]-'0';
            idx+=1;
        }
        if(dartResult[idx]=='D')
            num=num*num;
        else if(dartResult[idx]=='T')
            num=num*num*num;
        idx+=1;
        if(idx<n && dartResult[idx]=='*'){
            if(!v.empty())
                answer+=v.back();
            num*=2;
            idx+=1;
        }
        else if(idx<n && dartResult[idx]=='#'){
            num=-num;
            idx+=1;
        }
        answer+=num;
        v.push_back(num);
    }
    return answer;
}