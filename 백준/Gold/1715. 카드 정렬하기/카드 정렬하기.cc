#include <iostream>
#include <vector>
#include <queue>


using namespace std;

int main() {
	priority_queue<int,vector<int>,greater<>> pq;

	int n;
	cin >> n;
	if (n == 1) {
		int a;
		cin >> a;
		cout << 0;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		pq.push(num);
	}
	int answer = 0;
	for (int i = 0; i < n-1; i++) {
		int res = pq.top();
		pq.pop();
		res += pq.top();
		pq.pop();
		pq.push(res);
		answer += res;
	}
	cout << answer;
}