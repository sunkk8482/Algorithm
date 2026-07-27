#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool solution(string s) {
	if (s.size() != 4 && s.size() != 6)
	{
		return false;
	}
	for (auto i : s)
	{
		if (i < '0' || i > '9')return false;
	}
	return true;
}