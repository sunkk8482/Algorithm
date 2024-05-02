#include <iostream>
#include <algorithm>
#include <queue>


using namespace std;
int arr[101];
int N, M;
int dist[101];
int main() {
	cin >> N >> M;
	for (int i = 1; i <= 100; i++) {
		arr[i] = i;
	}
	
	for (int i = 0; i < N + M; i++) {
		int a, b;
		cin >> a >> b;
		arr[a] = b;
	}

	for (int i = 0; i < 101; i++) {
		dist[i] = 2134567890;
	}

	queue<int> q;
	q.push(1);
	dist[1] = 0;

	while (!q.empty()) {
		int now = q.front();

		q.pop();
		if (now == 100) {
			cout << dist[100];
			return 0;
		}
		int now_dist = dist[now];
		for (int i = 1; i <= 6; i++) {
			int next = now + i;
			int next_dist = now_dist + 1;
			if (next > 100)continue;
			if (next_dist >= dist[arr[next]])continue;
			q.push(arr[next]);
			dist[arr[next]] = next_dist;
		}
	}


}