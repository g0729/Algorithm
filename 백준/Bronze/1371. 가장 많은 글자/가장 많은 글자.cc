#include <bits/stdc++.h>
using namespace std;

int alpha[26];

int main()
{
  char a;

  while (1)
  {
    char a;
    cin >> a;
    if (cin.eof())
      break;
    alpha[a - 'a']++;
  }

  int MAX = 0;

  for (int i = 0; i < 26; i++)
  {
    if (alpha[i] > MAX)
      MAX = alpha[i];
  }

  for (int i = 0; i < 26; i++)
  {
    char temp;
    if (alpha[i] == MAX)
    {
      temp = 'a' + i;
      cout << temp;
    }
  }
}