#include <string>
#include <vector>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    vector<int> cntX(10),cntY(10);
    
    for(int i = 0 ;i<X.length();i++){
        cntX[X[i]-'0']++;
    }
    for(int i = 0 ;i<Y.length();i++){
        cntY[Y[i]-'0']++;
    }
    for(int i=9;i>=0;i--){
        for(int j= 0 ;j<min(cntX[i],cntY[i]);j++)
            answer.push_back(i+'0');
    }
    if(answer.length()==0)
        return "-1";
    int idx=0;
    if(answer[0]=='0')
    {
        while(answer[idx]=='0')
            idx++;
        answer=answer.substr(idx-1);
    }
    return answer;
}