#include<bits/stdc++.h>
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

if(s=="NLCS")
    cout<<"North London Collegiate School";
else if(s=="BHA")
    cout<<"Branksome Hall Asia";
else if(s=="KIS")
    cout<<"Korea International School";
else
    cout<<"St. Johnsbury Academy";

return 0;
}