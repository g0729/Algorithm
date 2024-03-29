#include <string>
#include <set>
#include <vector>
using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    set<char>se;
    for(int i =0 ;i<skip.length();i++){
        se.insert(skip[i]);
    }
    
    for(int i= 0 ; i<s.length();i++){
        char c= s[i]-'a';
        for(int j=0 ; j<index;j++){
            c= (c+1)%26;
            
            while(se.find(c+'a')!=se.end()){
                c=(c+1)%26;
            }
        }
        answer.push_back(c+'a');
    }
    return answer;
}