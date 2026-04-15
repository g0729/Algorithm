#include <iostream>
using namespace std;

int main() {
    cout.precision(3);
    for(int i = 0 ; i < 3 ; i++){
        double a;
        cin>>a;
        cout<<fixed<<a<<"\n";
    }
    return 0;
}