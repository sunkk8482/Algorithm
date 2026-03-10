#include <iostream>
#include <vector>
#include <queue>
#define LLONG_MAX     9223372036854775807
using namespace std;

int N, M;

vector<long long> vWard;

struct node {
	int dest;
	long long cost;
	bool operator<(node right) const
	{
		if (cost < right.cost)return false;
		if (cost > right.cost)return true;
		return false;
	}
};

vector<node> v[100001];
long long dist[1000001];

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		vWard.push_back(a);
	}
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({a,c});
	}

	for (int i = 0; i < N; i++) {
		dist[i] = LLONG_MAX;
	}

	priority_queue<node> pq;
	dist[0] = 0;
	pq.push({ 0,0 });
	while (!pq.empty())
	{
		node now = pq.top();
		pq.pop();
		if (now.dest == N - 1)break;
		if (dist[now.dest] < now.cost)continue;
		for (auto next : v[now.dest])
		{
			if (vWard[next.dest] == 1 && next.dest != N - 1)continue;
			long long  nowCost = dist[now.dest];
			long long  nextCost = nowCost + next.cost;
			if (dist[next.dest] <= nextCost)continue;
			pq.push({ next.dest,nextCost });
			dist[next.dest] = nextCost;
		}
	}
	if (dist[N - 1] == LLONG_MAX) {
		cout << -1;
	}
	else {
		cout << dist[N - 1];
	}
}