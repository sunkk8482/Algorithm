#include <iostream>
#include <queue>

using namespace std;

int N, M, K, X;


vector<int> alist[300001];
int dist[300001];

void dijkstra(int n) {
	
	priority_queue<int> pq;
	dist[n] = 0;
	pq.push(n);
	while (!pq.empty()) {
		int now = pq.top();
		pq.pop();
		for (int i = 0; i < alist[now].size(); i++) {
			int next = alist[now][i];
			int nextdist = dist[now] +1;
			if (nextdist >= dist[next])continue;
			pq.push(next);
			dist[next] = nextdist;
		}
	}

}

int main() {
	cin >> N >> M >> K >> X;
	for (int i = 1; i <= N; i++) {
		dist[i] = 2134567890;
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		alist[a].push_back( b);
	}
	
	dijkstra(X);

	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (dist[i] == K) {
			cnt++;
			cout << i << "\n";
		}
	}

	if (cnt == 0) {
		cout << "-1";
	}
}