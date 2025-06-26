#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
int s, e;

struct node {
	int start;
	int end;
	int power;
};

struct dest {
	int end;
	int power;
};

int parent[100001];
int visited[100001];
vector<vector<dest>> graph;

bool compare(node left, node right) {
	if (left.power > right.power) {
		return true;
	}
	return false;
}

void init() {
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
}

int find(int a) {
	if (parent[a] == a)return a;
	int ret = find(parent[a]);
	parent[a] = ret;
	return ret;
}

void setUnion(int a, int b) {
	int t1 = find(a);
	int t2 = find(b);
	if (t1 == t2)return;
	parent[t1] = t2;
}

int main() {
	cin >> N >> M;
	cin >> s >> e;
	graph = vector<vector<dest>>(N+1);
	init();
	vector<node> v;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ a,b,c });
	}
	sort(v.begin(), v.end(), compare);
	int cnt = 0;
	for (auto i : v) {
		if (cnt == N - 1)break;
		if (find(i.start) == find(i.end))continue;
		cnt++;
		graph[i.start].push_back({ i.end,i.power });
		graph[i.end].push_back({ i.start,i.power });
		setUnion(i.start, i.end);
	}
	queue<dest> q;
	q.push({ s,2134567890 });
	visited[s] = 1;
	bool find = false;
	while (!q.empty()) {
		dest now = q.front();
		if (now.end == e) {
			cout << now.power;
			find = true;
			break;
		}
		q.pop();
		for (auto i : graph[now.end]) {
			if (visited[i.end])continue;
			q.push({ i.end,min(now.power,i.power) });
			visited[i.end] = 1;
		}
	}
	if (!find)cout << 0;
}