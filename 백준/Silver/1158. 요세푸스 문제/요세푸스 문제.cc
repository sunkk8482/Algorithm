#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

queue<int> q;

int main() {
	int N, K;
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		q.push(i + 1);
	}
	cout << "<";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K-1; j++) {
			q.push(q.front());
			q.pop();
		}
		
		cout << q.front();
		q.pop();
		if (i != N - 1) {
			cout << ", ";
		}
		else {
			cout << ">";
		}

	}

}
