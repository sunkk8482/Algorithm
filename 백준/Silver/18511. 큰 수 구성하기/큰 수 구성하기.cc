#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int N, K;

vector<int> answer;

bool fdind = false;
void fun(int max_level, int level) {

	if (level == max_level) {
	
	int		num = answer[0];
		for (int i = 1; i < level; i++) {
			num *= 10;
			num += answer[i];
		}
		if (num <= N) {
			cout << num;
			fdind = true;
		}
		return;
	}

	for (int i = 0; i < v.size(); i++) {
		if (fdind) {
			return;
		}
		answer.push_back(v[i]);
		fun(max_level, level + 1);
		answer.pop_back();
	}
}

int main() {
	cin >> N >> K;

	for (int i = 0; i < K; i++) {
		int number;
		cin >> number;
		v.push_back(number);
	}

	sort(v.begin(), v.end(), greater<int>());
	int sizenum = N;
	int size = 0;
	while (sizenum != 0) {
		size++;
		sizenum /= 10;
	}
	for (int i = size; i >= 1; i--) {
		fun(i, 0);
	}
}