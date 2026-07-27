#include <string>
#include <vector>

using namespace std;

int gcd2(int a, int b) {
	while (b != 0) {
		int temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

int lcm(int a, int b) {
	return a * b / gcd2(a, b);
}

vector<int> solution(int n, int m) {
    vector<int> answer;
	answer.push_back(gcd2(n, m));
	answer.push_back(lcm(n, m));
    return answer;
}