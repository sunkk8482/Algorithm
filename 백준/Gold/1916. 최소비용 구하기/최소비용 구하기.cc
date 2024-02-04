#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;

struct node {
	int dest;
	int cost;
	bool operator< (node right)const {
		if (cost < right.cost)return false;
		if (cost > right.cost)return true;
		return false;
	}
};

vector<node> v[1001];

int dist[1001];

void fun(int num) {
	priority_queue<node> pq;
	node input{ num,0 };
	pq.push(input);
	dist[num] = 0;
	while (!pq.empty()) {
		node now = pq.top();
		pq.pop();
		if (dist[now.dest] < now.cost)continue;
		for (int i = 0; i < v[now.dest].size(); i++) {
			node next = v[now.dest][i];
			int nextdist = dist[now.dest] + next.cost;
			if (nextdist >= dist[next.dest])continue;
			pq.push({next.dest,nextdist});
			dist[next.dest] = nextdist;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < 1001; i++) {
		dist[i] = 2134567890;
	}
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
	
	int a, b;
	cin >> a >> b;
	fun(a);
	cout << dist[b];
}