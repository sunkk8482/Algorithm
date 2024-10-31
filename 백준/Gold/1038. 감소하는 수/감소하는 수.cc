#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 0 1 2 3 4 5 6 7 8 9

// 10 

// 20 21

// 30 31 32 40

//210

int n;

vector<long long> v;

int main() {
	cin >> n;
	queue<long long> q;
	
	for (int i = 0; i < 10; i++) {
		q.push(i);
		v.push_back(i);
	}

	if (n <= 9) {
		cout << v[n];
		return 0;
	}

	while (v.size() <= n) {
		if (q.empty()) {
			cout << -1;
			return 0;
		}
		long long now = q.front();
		q.pop();

		int last = now % 10;
		now *= 10;
		for (int i = 0; i <=last-1; i++) {
			q.push(now + i);
			v.push_back(now + i);
		}
	}

	cout << v[n];

}