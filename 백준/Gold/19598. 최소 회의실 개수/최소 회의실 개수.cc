#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
	int start;
	int end;

	bool operator<(const node s) const {
		return this->end > s.end;
	}
};

bool compare(node left, node right) {
	if (left.start < right.start) {
		return true;
	}
	return false;
}



int main() {
	int n;
	cin >> n;
	vector<node> v;
	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;
		v.push_back({ s,e });
	}
	sort(v.begin(), v.end(),compare);

	priority_queue<node> pq;
	for (auto i : v) {
		if (pq.empty()) {
			pq.push(i);
		}
		else {
			if (pq.top().end > i.start) {
				pq.push(i);
			}
			else {
				pq.pop();
				pq.push(i);
			}
		}
	}
	cout << pq.size();
}


/*

0 40

5 10

15 30





0 40

*/