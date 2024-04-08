#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    for(int i = 0 ; i<s.length();i++){
        if(s[i]==' ')
            continue;
        if(s[i]>='a'&&s[i]<='z')
            s[i]=(s[i]-'a'+n)%26+'a';
        else
            s[i]=(s[i]-'A'+n)%26+'A';
    }
    
    return s;
}