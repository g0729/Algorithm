#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;

    if(s=="fdsajkl;"||s=="jkl;fdsa")
        cout<<"in-out";
    else if(s=="asdf;lkj"||s==";lkjasdf")
        cout<<"out-in";
    else if(s=="asdfjkl;")
        cout<<"stairs";
    else if(s==";lkjfdsa")
        cout<<"reverse";
    else
        cout<<"molu";
    return 0;
}