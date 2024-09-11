#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long dist[501];


/*
a,b,c가 있다.
*/
int n, m;

struct edge {
	int from;
	int to;
	int cost;
};
vector<edge> v;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int from;
		int to;
		int cost;
		cin >> from >> to >> cost;
		v.push_back({ from,to,cost });
	}
	for (int i = 1; i <= n; i++) {
		dist[i] = 2134567890;
	}
	dist[1] = 0;

	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < m; j++) {
			int from = v[j].from;
			int to = v[j].to;
			int cost = v[j].cost;
			if (dist[from] == 2134567890)continue;
			if (dist[to] > dist[from] + cost)dist[to] = dist[from] + cost;
		}
	}

	for (int i = 0; i < m; i++) {
		int from = v[i].from;
		int to = v[i].to;
		int cost = v[i].cost;
		if (dist[from] == 2134567890) continue;
		if (dist[to] > dist[from] + cost) {
			cout << "-1";
			return 0;
		}
	}
	
	for (int i = 2; i <= n; i++) {
		if (dist[i] != 2134567890) {
			cout << dist[i] << "\n";
		}
		else {
			cout << "-1\n";
		}
	}
}