#include <string>
#include <vector>

using namespace std;

int solution(int coin, vector<int> cards) {
    int answer = 0;
    int n=cards.size();
    
    vector<bool>owned(n+1);
    vector<bool>visited(n+1);
    
    for(int  i = 0 ; i<n/3;i++){
        owned[cards[i]]=true;
        visited[cards[i]]=true;
    }
    
    int cnt=0;
    
    for(int i = 1;  i<=n/2;i++){
        if(owned[i]&&owned[n+1-i]){
            cnt++;
        }
    }
    
    int round=1;
    int ableToMatch=0;
    for(int i = n/3;i<n;i+=2){
        for(int j = 0 ; j<2;j++){
            int cur=cards[i+j];
            visited[cur]=true;
            
            if(owned[n+1-cur]&&coin){
                owned[cur]=true;
                coin--;
                cnt++;
            }
            else{
                if(visited[n+1-cur]){
                    ableToMatch++;
                }
            }
        }
        
        if(cnt<round){
            if(coin<=1) break;
            
            if(ableToMatch==0) break;
            
            cnt+=1;
            ableToMatch-=1;
            coin-=2;
            
        }
        
        round++;
    }
    
  
    return round;
}