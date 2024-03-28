#include <bits/stdc++.h>
using namespace std;

map<string,int>m={{"black",0},{"brown",1},{"red",2},{"orange",3},{"yellow",4},{"green",5},{"blue",6},{"violet",7},	{"grey",8},{"white",9}};

int main()
{
	string s;

	cin>>s;

	long long res=0;

	res+=m[s]*10;

	cin>>s;

	res+=m[s];

	cin>>s;

	for (int i = 0; i < m[s]; i++)
	{
		res=res*10;
	}
	
	cout<<res;
}