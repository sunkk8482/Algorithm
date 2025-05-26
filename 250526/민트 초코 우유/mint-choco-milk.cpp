#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

#define MAX 55
#define TMINT 1
#define CHOKO 2
#define MILK 4

int N, T;
int food[MAX][MAX];
int power[MAX][MAX];
int shield[MAX][MAX];
int visited[MAX][MAX];

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

struct Group {
    int y, x, power, food;
};

vector<Group> groupList[4];

int foodTypeCount(int f) {
    int cnt = 0;
    for (int i = 0; i < 3; i++) {
        if (f & (1 << i)) cnt++;
    }
    return cnt;
}

bool cmp(const Group &a, const Group &b) {
    if (a.power != b.power) return a.power > b.power;
    int at = foodTypeCount(a.food);
    int bt = foodTypeCount(b.food);
    if (at != bt) return at < bt;
    if (a.y != b.y) return a.y < b.y;
    return a.x < b.x;
}

void morning() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            power[i][j]++;
}

void lunch() {
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < 4; i++) groupList[i].clear();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j]) continue;

            int f = food[i][j];
            int maxP = power[i][j];
            int repY = i, repX = j;
            queue<pair<int, int>> q;
            vector<pair<int, int>> members;

            q.push({i, j});
            visited[i][j] = 1;
            members.push_back({i, j});

            while (!q.empty()) {
                auto [y, x] = q.front(); q.pop();
                for (int d = 0; d < 4; d++) {
                    int ny = y + dy[d];
                    int nx = x + dx[d];
                    if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
                    if (visited[ny][nx]) continue;
                    if (food[ny][nx] != f) continue;
                    visited[ny][nx] = 1;
                    q.push({ny, nx});
                    members.push_back({ny, nx});
                }
            }

            for (auto [y, x] : members) {
                if (power[y][x] > maxP) {
                    maxP = power[y][x]; repY = y; repX = x;
                } else if (power[y][x] == maxP) {
                    if (y < repY || (y == repY && x < repX)) {
                        repY = y; repX = x;
                    }
                }
            }

            for (auto [y, x] : members) {
                if (y == repY && x == repX) continue;
                power[y][x]--;
                power[repY][repX]++;
            }

            int type = foodTypeCount(f);
            groupList[type].push_back({repY, repX, power[repY][repX], f});
        }
    }
}

void spread(Group g) {
    if (shield[g.y][g.x]) return;

    int dir = g.power % 4;
    int x = g.power - 1;
    power[g.y][g.x] = 1;
    int y = g.y, x_ = g.x;

    while (x > 0) {
        y += dy[dir];
        x_ += dx[dir];
        if (y < 0 || x_ < 0 || y >= N || x_ >= N) break;
        if (food[y][x_] == g.food) continue;

        shield[y][x_] = 1;
        if (x > power[y][x_]) {
            x -= power[y][x_] + 1;
            power[y][x_]++;
            food[y][x_] = g.food;
        } else {
            power[y][x_] += x;
            food[y][x_] |= g.food;
            break;
        }
    }
}

void dinner() {
    memset(shield, 0, sizeof(shield));
    for (int i = 1; i <= 3; i++) {
        sort(groupList[i].begin(), groupList[i].end(), cmp);
        for (auto &g : groupList[i]) spread(g);
    }
}

void calc() {
    int result[8] = {0};
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            result[food[i][j]] += power[i][j];

    cout << result[7] << " " << result[3] << " " << result[5] << " " << result[6] << " " << result[4] << " " << result[2] << " " << result[1] << endl;
}

void input() {
    cin >> N >> T;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        for (int j = 0; j < N; j++) {
            if (s[j] == 'T') food[i][j] = TMINT;
            else if (s[j] == 'C') food[i][j] = CHOKO;
            else food[i][j] = MILK;
        }
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> power[i][j];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    for (int t = 0; t < T; t++) {
        morning();
        lunch();
        dinner();
        calc();
    }
    return 0;
}