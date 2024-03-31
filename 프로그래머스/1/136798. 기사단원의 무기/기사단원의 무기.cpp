#include <iostream>
#include <string>
#include <vector>

using namespace std;

int cal(int n){
    if(n==1)
        return 1;
    int res=0;
    for(int i=1; i*i<=n;i++){
        if(i*i==n)
            res+=1;
        else if(n%i==0)
            res+=2;
    }
    return res;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    
    for(int i =1 ; i<=number;i++){
        int temp=cal(i);
        if(temp>limit)
            answer+=power;
        else
            answer+=temp;
    }
    return answer;
}