#include <string>
#include <vector>

using namespace std;
vector<bool>isPrime(1000001,true);

void eratos(int& n){
    isPrime[1]=false;
    for(int i =2 ;i*i<=n;i++){
        if(isPrime[i]){
            for(int j = i*i;j<=n;j+=i){
                isPrime[j]=false;
            }
        }
    }
}
int solution(int n) {
    int answer = 0;
    eratos(n);
    for(int i =1 ; i<=n;i++){
        if(isPrime[i])
            answer++;
    }
    return answer;
}