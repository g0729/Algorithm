#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    int cnt[2]={0,};
    char c=0;
    for(int i = 0 ; i<s.length();i++){
        if(c==0){
            c=s[i];
            cnt[0]=1;
            cnt[1]=0;
        }
        else{
            if(s[i]!=c)
                cnt[1]++;
            else
                cnt[0]++;
            if(cnt[1]==cnt[0]){
                c=0;
                answer++;
            }
        }
    }
    if(c!=0)
        answer++;
    return answer;
}