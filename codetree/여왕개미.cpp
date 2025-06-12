#include <iostream>
#include <vector>

using namespace std;

int Q;

struct node {
	int x;
	bool alive;
};

vector<node> vAntHouse;

void constructTown() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		vAntHouse.push_back({ x,true });
	}
}

void constructAnt() {
	int p;
	cin >> p;
	vAntHouse.push_back({ p,true });
}

void deleteAnt() {
	int q;
	cin >> q;
	vAntHouse[q-1].alive = false;
}

void sight() {
	int r;
	cin >> r;
	int left = 0;
	int right = 1000000000;
	int ret = 2134567890;
	while (left <= right) {
		int prevPosition = -1000000000;
		int mid = (left + right) / 2;
		int antCnt = 0;
		for (auto i : vAntHouse) {
			if (!i.alive)continue;
			int currentPosition = i.x;
			if (currentPosition - prevPosition > mid) {
				antCnt++;
				prevPosition = currentPosition;
			}
		}
		// 
		if (antCnt <= r) {
			ret = mid;
			right = mid - 1;
		}
		// 줄여야함
		else {
			left = mid + 1;
		}
	}
	cout << ret<<"\n";
}

int main() {
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int query;
		cin >> query;
		if (query == 100)constructTown();
		else if (query == 200)constructAnt();
		else if (query == 300)deleteAnt();
		else if (query == 400)sight();
	}
}