#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <iostream>
using namespace std;
int f(int n,int m)
{
    if(n==m)
        return 1;
    unordered_set<int>dp[9];
    dp[1].insert(n);
    int now=n;
    for(int i =2 ; i<=8;i++){
        now=now*10+n;
        dp[i].insert(now);
        if(now==m)
            return i;
        for(int j = 1;j<i;j++)
        {
            for(auto a:dp[j]){
                for(auto b:dp[i-j]){

                    if(a+b==m ||a-b==m||a*b==m||a/b==m)
                        return i;
                    dp[i].insert(a+b);
                    if(a-b>0)
                        dp[i].insert(a-b);
                    dp[i].insert(a*b);
                    if(a/b!=0)
                        dp[i].insert(a/b);
                }
            }
        }
    }
    return -1;
}
int solution(int N, int number) {
    return f(N,number);
}