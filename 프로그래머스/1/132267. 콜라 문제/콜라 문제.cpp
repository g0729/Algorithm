#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    while(n>=a){
        int temp=(n/a)*b;
        n=n%a+temp;
        answer+=temp;
        
    }
    return answer;
}