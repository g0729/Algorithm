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

int n;
string a,b;
cin>>n>>a>>b;

for (int i = 0; i < a.length(); i++)
{
    if((a[i]-'0'+(n%2))%2!=(b[i]-'0'))
    {
        cout<<"Deletion failed";
        return 0;
    }
}

cout<<"Deletion succeeded";
return 0;
}