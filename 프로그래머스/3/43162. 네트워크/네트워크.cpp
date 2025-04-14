#include <string>
#include <vector>

using namespace std;

int visited[201];

void dfs(int n, vector<vector<int>> computers,int k) {
    for (int i = 0; i < n; i++) {
        if (computers[k][i]) {
            if (visited[i])continue;
            visited[i] = 1;
            dfs(n, computers, i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i])continue;
        answer++;
        dfs(n, computers, i);
    }
    return answer;
}