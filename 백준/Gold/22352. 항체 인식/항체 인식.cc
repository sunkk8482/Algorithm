#include <iostream>
#include <queue>
using namespace std;
int bef[32][32];
int aft[32][32];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };
int n, m;

void bfs(int a, int b, int bf, int af) {
    queue<pair<int, int>> q;
    q.push(make_pair(a, b));
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) { 
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < m && nx >= 0 && ny < n && ny >= 0) {
                if (bef[ny][nx] == bf) { 
                    bef[ny][nx] = af; 
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> bef[i][j]; 
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> aft[i][j]; 
        }
    }
    bool injected = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!injected) { 
                if (bef[i][j] != aft[i][j]) {
                    bfs(j, i, bef[i][j], aft[i][j]);
                    bef[i][j] = aft[i][j]; 
                    injected = true;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (bef[i][j] != aft[i][j]) {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
    return 0;
} 