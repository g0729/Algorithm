#include <bits/stdc++.h>
using namespace std;

void reverse(string &s)
{
	for (int i = 0; i < s.length() / 2; i++)
	{
		char temp = s[i];
		s[i] = s[s.length() - i - 1];
		s[s.length() - i - 1] = temp;
	}
}

string my_plus(string a, string b)
{
	string res;
	reverse(a);
	reverse(b);

	while (a.length() != b.length())
	{
		if (a.length() > b.length())
			b += '0';
		else
			a += '0';
	}
	int carry = 0;
	int sum;
	for (int i = 0; i < a.length(); i++)
	{
		sum = a[i] - '0' + b[i] - '0' + carry;

		if (sum >= 10)
		{
			carry = 1;
			sum -= 10;
		}
		else
			carry = 0;
		res += sum + '0';
	}

	if (carry == 1)
		res += '1';
	reverse(res);
	return res;
}

string my_multip(string a, string b)
{
	string res = "0";
	reverse(b);
	for (int i = 0; i < b.length(); i++)
	{
		string temp = "0";
		for (int j = 0; j < b[i] - '0'; j++)
		{
			temp = my_plus(temp, a);
		}
		for (int j = 0; j < i; j++)
		{
			temp += '0';
		}
		res = my_plus(res, temp);
	}
	return res;
}

bool check(string a, string b)
{
	if (a.length() > b.length())
		return true;
	else if (a.length() < b.length())
		return false;
	else
	{
		for (int i = 0; i < a.length(); i++)
		{
			if (a[i] == b[i])
				continue;

			if (a[i] > b[i])
				return true;
			else
				return false;
		}
	}
}
string my_substr(string a, string b)
{
	string temp1, temp2, res;
	temp1 = a;
	temp2 = b;
	if (!check(temp1, temp2))
	{
		string temp3 = temp1;
		temp1 = temp2;
		temp2 = temp3;
	}

	reverse(temp1);
	reverse(temp2);

	while (temp1.length() != temp2.length())
	{
		if (temp1.length() > temp2.length())
			temp2 += '0';
		else
			temp1 += '0';
	}
	int sum, carry;
	carry = 0;

	for (int i = 0; i < temp1.length(); i++)
	{
		sum = temp1[i] - '0' - (temp2[i] - '0') - carry;
		if (sum < 0)
		{
			carry = 1;
			sum += 10;
		}
		else
			carry = 0;
		res += sum + '0';
	}

	reverse(res);
	for (int i = 0; i < res.length(); i++)
	{
		if (res[i] != '0')
		{
			res = res.substr(i);
			break;
		}
	}

	return res;
}
int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string a, b;
	cin >> a >> b;

	string res1, res2, res3;
	if (a[0] != '-' && b[0] != '-')
	{
		res1 = my_plus(a, b);
		res3 = my_multip(a, b);
		if (a == b)
			res2 = "0";
		else if (!check(a, b))
			res2 = '-' + my_substr(a, b);
		else
			res2 = my_substr(a, b);
	}
	if (a[0] != '-' && b[0] == '-')
	{
		string temp = b.substr(1);
		res2 = my_plus(a, temp);
		res3 = '-' + my_multip(a, temp);
		if (a == temp)
			res1 = "0";
		else if (check(a, temp))
			res1 = my_substr(a, temp);
		else
			res1 = '-' + my_substr(a, temp);
	}
	if (a[0] == '-' && b[0] != '-')
	{
		string temp = a.substr(1);
		if (temp == b)
			res1 = '0';
		else if (!check(temp, b))
			res1 =my_substr(temp, b);
		else
			res1 = '-' + my_substr(temp, b);
		res2='-'+my_plus(temp,b);
		res3='-'+my_multip(temp,b);
	}
	if(a[0]=='-'&&b[0]=='-')
	{
		string temp1,temp2;
		temp1=a.substr(1);
		temp2=b.substr(1);

		res1='-'+my_plus(temp1,temp2);
		if(temp1==temp2)
		res2='0';
		else if(!check(temp1,temp2))
		res2=my_substr(temp1,temp2);
		else
		res2='-'+my_substr(temp1,temp2);
		res3=my_multip(temp1,temp2);
	}
	cout << res1 << "\n"
		 << res2 << "\n"
		 << res3;
}