#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
	if (a == b) {
		return a;
	}
	int min = 0, max = 0;
	if (a < b)
	{
		min = a;
		max = b;
	}
	else
	{
		min = b;
		max = a;
	}
	long long sum = 0;
	for (int i = min; i <= max; i++)
	{
		sum += i;
	}
	return sum;
}