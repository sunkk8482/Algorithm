#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int boss[110002];

int N, M;
void init() {
	for (int i = 1; i <= 110001; i++) {
		boss[i] = i;
	}
}

int find(int t) {
	if (boss[t] == t)return t;
	int ret = find(boss[t]);
	boss[t] = ret;
	return ret;
}

void set_union(int a, int b) {
	int t1 = find(a);
	int t2 = find(b);
	if (t1 == t2)return;
	boss[b] = a;
}

struct node {
	int s;
	int e;
	int cost;
};

bool compare(node a, node b) {
	if (a.cost < b.cost)return true;
	return false;
}
vector<node>v;
int visit[110002];
vector<int> graph[110002];
void dfs(int x) {
	visit[x] = true;
	for (int i = 0; i < graph[x].size(); i++) {
		if (!visit[graph[x][i]]) {
			dfs(graph[x][i]);
		}
	}
}

int visited[110002];
int main() {
	init();
	cin >> N >> M;
	long long  sum = 0;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ a,b,c });
		graph[a].push_back(b);
		graph[b].push_back(a);
		sum += c;
	}

	dfs(1);
	for (int i = 1; i <= N; i++) {
		if (!visit[i]) {
			printf("-1");
			return 0;
		}
	}


	sort(v.begin(), v.end(), compare);
	
	int cnt = N - 1;
	long long  answer = 0;
	for (auto i : v) {
		if (cnt == 0)break;
		if (find(i.s) == find(i.e))continue;
		set_union(find(i.s), find(i.e));
		visited[i.s] = 1;
		visited[i.e] = 1;
		answer += i.cost;
		cnt--;
	}

	cout << sum - answer;


}