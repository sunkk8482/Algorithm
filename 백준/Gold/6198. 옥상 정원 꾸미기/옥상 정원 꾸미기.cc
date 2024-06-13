#include <iostream>
#include <stack>

using namespace std;

stack<int> s;

int main() {
	int n;
	cin >> n;
	long long answer =0;
	for (int i = 0; i < n; i++) {
		int number;
		cin >> number;
		if (i == 0) {
			s.push(number);
			continue;
		}
		
		while (number >= s.top()) {
			s.pop();
			if (s.empty())break;
		}

		answer += s.size();
		s.push(number);
	}
	cout << answer;
}

/*

10

작은거일때
12 2

1개 

1개

2개

0개

1개




큰거일때

*/