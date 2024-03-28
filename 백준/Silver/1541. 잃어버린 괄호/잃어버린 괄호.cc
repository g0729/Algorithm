#include<iostream>
using namespace std;
string s;
int cal(int begin, int end)
{
	int length = end - begin+1;
	int res=0;
	int n = 1;
	for (int i = 0; i < length; i++)
	{
		res += (s[end - i] - '0') * n;
		n *= 10;
	}

	return res;
}
int main()
{
	cin >> s;
	int mi = 0;
	int pl = 0;
	int res = 0;
	bool first = false;
	int start = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '+' && first == false)
		{
		
			pl += cal(start, i - 1);
			start = i + 1;
		}
		if (first == true)
		{
			if (s[i] == '+' || s[i] == '-')
			{
			
				mi += cal(start, i - 1);
				start = i + 1;
			}
		}
		if (s[i] == '-' && first == false)
		{

			pl += cal(start, i - 1);
			start = i + 1;
			first = true;
		}

	}
	if (first == false)
	{
		pl += cal(start, s.length() - 1);
	}
	else
	{
		mi += cal(start, s.length() - 1);
	}
	cout << pl - mi;
}