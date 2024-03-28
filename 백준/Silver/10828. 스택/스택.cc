#include<iostream>
#include<stack>

using namespace std;

stack<int> s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int count = 0;
	cin >> count;

	string command = " ";
	int input = 0;
	for (int i = 0; i < count; i++)
	{
		cin >> command;
		if (command == "push")
		{
			cin >> input;
			s.push(input);
		}
		else if (command == "top")
		{
			if (s.empty()) cout << -1 << "\n";
			else
			{
				cout << s.top() << "\n";
			}
		}
		else if (command == "size")
		{
			cout << s.size() << "\n";
		}
		else if (command == "empty")
		{
			if (s.empty()) cout << "1" << "\n";
			else cout << "0" << "\n";

		}
		else if(command=="pop")
		{
			if (s.empty()) cout << -1<<"\n";
			else
			{
				cout << s.top() << "\n";
				s.pop();
			}
		}
	}
}