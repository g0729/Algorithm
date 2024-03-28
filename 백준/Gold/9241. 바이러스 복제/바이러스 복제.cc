#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s1,s2;
	cin>>s1>>s2;

	int left=0;
	while(left<s1.length()&&s2.length()&&s1[left]==s2[left])
	{
		left++;
	}
	
	int right=0;

	while(right<s1.length()&&right<s2.length()&&s1[s1.length()-right-1]==s2[s2.length()-right-1])
	{
		right++;
	}
	
	right=s2.length()-right;
	int res=max(right-left,0);
	int temp=s2.length()-s1.length();
	cout<<max(res,temp);
}