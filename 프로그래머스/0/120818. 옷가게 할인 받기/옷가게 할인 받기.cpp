#include <string>
#include <vector>

using namespace std;

int solution(int price) {
    
    if(price<100000)
        return price;
    else if(price<300000)
        return 0.95*price;
    else if(price<500000)
        return 0.9*price;
    else
        return 0.8*price;
    
}