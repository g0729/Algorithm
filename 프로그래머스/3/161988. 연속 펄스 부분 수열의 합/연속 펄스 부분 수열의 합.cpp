#include <string>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

ll solution(vector<int> sequence) {
    ll answer = 0;
    ll n =sequence.size();
    vector<vector<ll>>dp(n+1,vector<ll>(2));
    
    for(int i = 1 ; i<=n;i++){
        dp[i][0]=max(dp[i-1][1]+sequence[i-1],(ll)sequence[i-1]);
        dp[i][1]=max(dp[i-1][0]-sequence[i-1],(ll)-sequence[i-1]);
        
        answer=max(answer,max(dp[i][0],dp[i][1]));
    }
    
    return answer;
}