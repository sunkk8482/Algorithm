#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
	int start;
	int end;
};

vector<node>v;

bool com(node left, node right) {
	if (left.end < right.end) {
		return true;
	}
	else if (left.end == right.end) {
		if (left.start < right.start) {
			return true;
		}
		else {
			return false;
		}
	}
	return false;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;
		v.push_back({ s,e });
	}
	sort(v.begin(), v.end(), com);
	
	int time = v[0].end;

	int cnt = 1;
	for (int i = 1; i < v.size(); i++) {
		int now_start = v[i].start;
		if (time <= now_start) {
			cnt++;
			time = v[i].end;
		}
	}

	cout << cnt;

}