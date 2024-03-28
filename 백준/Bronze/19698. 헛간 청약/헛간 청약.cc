#include<bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
int n,w,l,h;
cin>>n>>w>>h>>l;

cout<<min(n,(w/l)*(h/l));

return 0;
}