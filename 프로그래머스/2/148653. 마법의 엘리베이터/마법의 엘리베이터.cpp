#include <string>
#include <vector>
#include <iostream>
using namespace std;
int n;
int res=1e9;
int pow(int exp){
    int res=1;
    while(exp--){
        res*=10;
    }
    return res;
}
void dfs(int now,int num,int cnt){
    if(now==n-1){
        int temp=pow(now);
        int a=(num/temp)%10;
        if(a==0){
            res=min(res,cnt+1);
        }
        else{
        res=min(res,cnt+a);
        res=min(res,cnt+(11-a));
        }
        return ;
    }
    
    int temp=pow(now);
    int a=(num/temp)%10;
    dfs(now+1,num-a*temp,cnt+a);
    dfs(now+1,num+(10-a)*temp,cnt+(10-a));
}
int solution(int storey) {
    int answer = 0;
    string s=to_string(storey);
    n=s.length();
    dfs(0,storey,0);
    return res;
}