#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    for(int i=1 ; i*i<=n;i++){
        if(i*i==n)
            answer+=1;
        else if(n%i==0)
            answer+=2;
    }
    return answer;
}