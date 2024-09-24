#include <iostream>
#include <vector>

using namespace std;

vector<int> list;
vector<int> input;

int main() {
	int N;
	cin >> N;
	int number;

	for (int i = 0; i < N; i++) {
		cin >> number;
		input.push_back(number);
	}

	list.push_back(input[0]);
	for (int i = 1; i < N; i++) {
		if (list.back() < input[i]) {
			list.push_back(input[i]);
		}
		else {
			int idx = lower_bound(list.begin(), list.end(), input[i]) - list.begin();
			list[idx] = input[i];
		}
	}

	cout << list.size();
}