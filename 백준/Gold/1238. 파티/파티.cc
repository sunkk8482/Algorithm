#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct node {
	int dest;
	int cost;

};

bool operator<(node a, node b) {
	if (a.cost < b.cost)return false;
	return true;
}

int dist[1010];
int dat[1010];
vector<node> v[1010];

void dijkstra(int start) {
	priority_queue<node> pq;
	dist[start] = 0;
	pq.push({ start,0 });
	while (!pq.empty()) {
		node now = pq.top();
		pq.pop();
		for (int i = 0; i < v[now.dest].size(); i++) {
			int next = v[now.dest][i].dest;
			int n_cost = v[now.dest][i].cost;
			if (dist[next] > now.cost + n_cost) {
				dist[next] = now.cost + n_cost;
				pq.push({ next,now.cost + n_cost });
			}
		}
	}
}

int N, M, X, answer;

int main() {
	
	cin >> N >> M >> X;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dist[j] = 2134567890;
		}
		dijkstra(i);
		dat[i] = dist[X];
	}
	for (int i = 1; i <= N; i++) {
		dist[i] = 2134567890;
	}
	dijkstra(X);
	for (int i = 1; i <= N; i++) {
		dat[i] = dat[i] + dist[i];
	}
	sort(dat + 1, dat + N + 1);
	answer = dat[N];
	cout << answer;
}