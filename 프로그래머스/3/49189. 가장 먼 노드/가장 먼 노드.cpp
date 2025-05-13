#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct node {
    int index;
    int cnt;
};

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> e(20002, vector<int>());
    for (auto i : edge) {
        e[i[0]].push_back(i[1]);
        e[i[1]].push_back(i[0]);
    }
    vector<int> dist(n + 1,0);
    for (int i = 1; i <= n; i++) {
        dist[i] = 2134567890;
    }
    dist[1] = 0;
    queue<node> q;
    q.push({ 1,0 });
    while (!q.empty()) {
        node now = q.front();
        q.pop();
        for (auto i : e[now.index]) {
            int next = dist[now.index] + 1;
            if (next >= dist[i])continue;
            q.push({ i,next });
            dist[i] = next;
        }
    }
    int maxx = -1;
    for (int i = 1; i <= n; i++) {
        maxx = max(maxx, dist[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (dist[i] == maxx) {
            answer++;
        }
    }
    return answer;
}