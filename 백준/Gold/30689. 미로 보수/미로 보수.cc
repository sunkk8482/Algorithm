#include <iostream>

#include <queue>

#include <vector>

#include <cmath>

#include <map>

#include <stack>

#include <cmath>

#include <unordered_map>

#include <cstring>

#include <algorithm>
using namespace std;
int N, M;
string arr[2000];
struct yx {
    int y, x;
};
int visited[2000][2000];
int done[2000][2000];
int cost[2000][2000];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0 ,1 , -1 };
int answer = 0;
unordered_map<char, int> m;
void dfs(int py, int px)
{
    //cout << py << " " << px << '\n';
    visited[py][px] = 1;
    int dir = m[arr[py][px]];
    int y = dy[dir] + py;
    int x = dx[dir] + px;
    if (x < 0 || y < 0 || x >= M || y >= N) {
        //out
        done[py][px] = 1;
        return;
    }
    if (done[y][x]) {
        done[py][px] = 1;
        return;
    }
    else if (visited[y][x]) {
        int sy = y;
        int sx = x;
        int cc = 987654321;
        do
        {
            cc = min(cc, cost[sy][sx]);
            int d = m[arr[sy][sx]];
            sy = dy[d] + sy;
            sx = dx[d] + sx;
        } while (sy != y || sx != x);
        answer += cc;
    }
    else dfs(y, x);
    done[py][px] = 1;
}
// 방문안한 노드에 대해 dfs 만약 다음 노드가 방문했을 경우 이전노드들의 결과
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    m['U'] = 1;
    m['D'] = 0;
    m['L'] = 3;
    m['R'] = 2;
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> cost[i][j];
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (done[i][j]) continue;
            dfs(i, j);
        }
    }
    cout << answer;
    return 0;
}