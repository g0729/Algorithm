#include <string>
#include <vector>

using namespace std;

int cal(long long num,long long level){
    long long temp=num/level;
    if(temp==2)
        return 0;
    if(level==1)
        return 1;
    return cal(num%level,level/5);
}
int solution(int n, long long l, long long r) {
    long long answer = 0;
    
    long long level=1;
    for(int i = 0 ; i<n-1;i++)
        level*=5;
    
    for(long long i = l-1;i<r;i++)
        answer+=cal(i,level);
    return answer;
}