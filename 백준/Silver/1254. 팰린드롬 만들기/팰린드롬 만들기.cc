#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin>>s;

	for(int i = 0 ; i<s.length();i++)
	{
		int left=i;
		int right=s.length()-1;
		bool flag=true;
		while(left<=right)
		{
			if(s[left]!=s[right])
			{
				flag=false;
				break;
			}
			left++;
			right--;
		}
		if(flag)
		{
			cout<<s.length()+i;
			return 0;
		}
	}
}