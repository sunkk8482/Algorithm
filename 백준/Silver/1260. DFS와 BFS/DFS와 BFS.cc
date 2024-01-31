#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> v;

int N, M, V;
int visited[1001];

void dfs(int level) {
	if (visited[level])return;
	cout << level << " ";
	visited[level] = 1;
	int size= v[level].size();
	for (int i = 0; i <size; i++) {
		dfs(v[level][i]);
	}
}
queue<int> q;

int qvisited[1001];
void bfs(int node) {
	q.push(node);
	qvisited[node] = 1;
	while (!q.empty()) {
		int now = q.front();
		cout << now << " ";
		q.pop();

		int size = v[now].size();
		for (int i = 0; i < size; i++) {
			if (qvisited[v[now][i]])continue;
			q.push(v[now][i]);
			qvisited[v[now][i]] = 1;
		}
	}
	
}


int main() {
	cin >> N >> M >> V;
	for (int i = 0; i <= N; i++) {
		v.push_back(vector<int>());
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int size = v.size();
	for (int i = 0; i < size; i++) {
		sort(v[i].begin(), v[i].end());
	}
	dfs(V);
	cout << "\n";
	bfs(V);
}