#include <iostream>
#include <string>

using namespace std;

int N;
string s;

int main()
{
	int minimum = 0;
	int maximum = 0;
	cin >> N >> s;
	if (s.size() % 2 == 1) {
		cout << "No\n";
		return 0;
	}
	for (int i = 0; i < N; i++) {
		switch (s.at(i))
		{
		case '(':
		{
			minimum++;
			maximum++;
		}break;
		case ')':
		{
			minimum--;
			maximum--;
		}break;
		case '?':
		{
			minimum--;
			maximum++;
		}break;
		}

		if (minimum < 0)minimum = 0;
		if (maximum < 0)
		{
			cout << "No";
			return 0;
		}
	}
	if (minimum == 0)
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}
}

