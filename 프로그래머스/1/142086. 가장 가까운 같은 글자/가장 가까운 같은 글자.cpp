#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<int>alpha(26,-1);
    
    for(int i =0 ; i<s.length();i++){
        if(alpha[s[i]-'a']==-1)
            answer.push_back(-1);
        else{
         answer.push_back(i-alpha[s[i]-'a']);   
        }
        alpha[s[i]-'a']=i;
    }
    
    return answer;
}