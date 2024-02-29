#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

/*
	0 0
	1000 0

	50 0
	0 50
	25 25

*/

struct node {
	int y;
	int x;
};

vector<node> stores;
int visited[101];

void program() {
	int n;
	cin >> n;
	int starty, startx;
	cin >> starty >> startx;
	for (int i = 0; i < n; i++) {
		int y, x;
		cin >> y >> x;
		stores.push_back({ y,x });
	}
	int endy, endx;
	cin >> endy >> endx;

	queue<node> q;
	q.push({ starty,startx });
	bool finish = false;
	while (!q.empty()) {
		node now = q.front();
		q.pop();

		for (int i = 0; i < stores.size(); i++) {
			int sty = stores[i].y;
			int stx = stores[i].x;
			if (visited[i])continue;
			if (abs(now.y - sty) + abs(now.x - stx) <= 1000) {
				q.push(stores[i]);
				visited[i] = 1;
			}
		}

		if (abs(now.y - endy) + abs(now.x - endx) <= 1000) {
			finish = true;
			break;
		}

	}

	if (finish) {
		cout << "happy\n";
	}
	else {
		cout << "sad\n";
	}
	

}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		program();

		for (int j = 0; j < 101; j++) {
			visited[j] = 0;
		}
		stores.clear();
	}
}