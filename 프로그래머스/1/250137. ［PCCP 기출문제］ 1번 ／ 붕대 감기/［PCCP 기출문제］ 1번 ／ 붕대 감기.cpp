#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    int last=attacks.back()[0];
    int atk_idx=0;
    int contd_succ=0;
    int now_health=health;
    for(int i = 1; i<=last;i++){
        if(attacks[atk_idx][0]==i){
            contd_succ=0;
            now_health-=attacks[atk_idx][1];
            atk_idx++;
            if(now_health<=0)
                return -1;
        }
        else{
            now_health+=bandage[1];
            contd_succ++;
            if(contd_succ==bandage[0]){
                contd_succ=0;
                now_health+=bandage[2];
            }
            now_health=min(now_health,health);
        }
        cout<<now_health<<endl;
    }
    return now_health;
}