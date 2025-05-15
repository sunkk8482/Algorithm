#include <iostream>
#include <vector>
using namespace std;

const int MAX = 200001;

int N;
vector<pair<int, int>> graph[MAX];  
int subtreeCount[MAX];              
long long subtreeDistSum[MAX];      // 각 노드를 루트로 하는 서브트리 내 거리 합
long long result[MAX];              // 각 노드를 기준으로 전체 거리합


void dfs1(int current, int parent) {
    subtreeCount[current] = 1;  // 자기 자신 포함

    for (int i = 0; i < graph[current].size(); i++) {
        int next = graph[current][i].first;
        int cost = graph[current][i].second;

        if (next == parent) continue;

        dfs1(next, current);
        subtreeCount[current] += subtreeCount[next];
        subtreeDistSum[current] += subtreeDistSum[next] + (long long)cost * subtreeCount[next];
    }
}

void dfs2(int current, int parent) {
    for (int i = 0; i < graph[current].size(); i++) {
        int next = graph[current][i].first;
        int cost = graph[current][i].second;

        if (next == parent) continue;

        result[next] = result[current] - (long long)subtreeCount[next] * cost
            + (long long)(N - subtreeCount[next]) * cost;

        dfs2(next, current);
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        graph[u].push_back(make_pair(v, t));
        graph[v].push_back(make_pair(u, t));
    }

    // 1번 노드를 루트로
    dfs1(1, 0);

    result[1] = subtreeDistSum[1];  // 루트 노드의 거리합
    dfs2(1, 0);

    for (int i = 1; i <= N; i++) {
        cout << result[i] << "\n";
    }

    return 0;
}