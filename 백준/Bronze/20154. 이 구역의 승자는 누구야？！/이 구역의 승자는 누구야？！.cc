#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000
int alpha[26] = {3, 2, 1, 2, 3, 3, 3, 3, 1, 1, 3, 1, 3, 3, 1, 2, 2, 2, 1, 2, 1, 1, 2, 2, 2, 1};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;

    int res=0;

    for (int i = 0; i < s.length(); i++)
    {
        res+=alpha[s[i]-'A'];
    }
    
    if(res%2==1)
        cout<<"I'm a winner!";
    else
        cout<<"You're the winner?";
    return 0;
}