#include<bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long
#define MOD 1000000007

int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

int n;
cin>>n;
cin.ignore();
while(n--)
{
	string s;
	getline(cin,s);

	s[0]=toupper(s[0]);

	cout<<s<<"\n";
}
return 0;
}