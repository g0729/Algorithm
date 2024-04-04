#include <string>
#include <vector>
#include <iostream>
#define ll long long
using namespace std;

int cal(int& n,ll& num){
    int x, y;
    x=num/n;
    y=num%n;
    
    if(x>=y)
        return x+1;
    else
        return y+1;
}
vector<int> solution(int n, ll left, ll right) {
    vector<int> answer;
    
    for(ll i =left;i<=right;i++)
        answer.push_back(cal(n,i));
    return answer;
}