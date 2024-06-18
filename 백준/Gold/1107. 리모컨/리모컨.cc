#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, M;

int dat[10];

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int number;
		cin >> number;
		dat[number] = 1;
	}

	int cnt = abs(N - 100);

	
	for (int i = 0; i < 1000000; i++) {
		bool avail = true;
		string ch = to_string(i);
		for (int j = 0; j < ch.size(); j++) {
			if (dat[ch.at(j) - '0']) {
				avail = false;
				break;
			}
		}
		if (avail) {
			int tmp = ch.size();
			tmp += abs(N - i);
			cnt = min(cnt,tmp);
		}
	}

	cout << cnt;

}