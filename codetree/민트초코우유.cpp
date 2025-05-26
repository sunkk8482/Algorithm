#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int food[51][51];
int power[51][51];
int shield[51][51];
int visited[51][51];

struct node {
	int y, x;
};

struct group {
	int food;
	int y, x;
	int g_power;
	bool operator==(const group& other) const {
		return food == other.food && y == other.y && x == other.x && g_power == other.g_power;
	}
};

namespace std {
	template <>
	struct hash<group> {
		size_t operator()(const group& g) const {
			return ((std::hash<int>()(g.food) ^ (std::hash<int>()(g.y) << 1)) >> 1)
				^ (std::hash<int>()(g.x) << 1)
				^ (std::hash<int>()(g.g_power) << 2);
		}
	};
}

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int N, T;
unordered_set<group> group_set;

void morning() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			power[i][j]++;
}

void makeGroup(int y, int x) {
	vector<node> team;
	int best_y = y, best_x = x, best_power = power[y][x], now_food = food[y][x];
	queue<node> q;
	q.push({ y,x });
	visited[y][x] = 1;
	team.push_back({ y,x });
	while (!q.empty()) {
		node now = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (visited[ny][nx] || food[ny][nx] != now_food) continue;
			visited[ny][nx] = 1;
			q.push({ ny, nx });
			team.push_back({ ny, nx });
			if (power[ny][nx] > best_power || (power[ny][nx] == best_power && (ny < best_y || (ny == best_y && nx < best_x)))) {
				best_y = ny; best_x = nx; best_power = power[ny][nx];
			}
		}
	}
	for (auto i : team) {
		if (i.y == best_y && i.x == best_x) continue;
		power[i.y][i.x]--;
		power[best_y][best_x]++;
	}
	group_set.insert({ now_food, best_y, best_x, power[best_y][best_x] });
}

void lunch() {
	fill(&visited[0][0], &visited[0][0] + sizeof(visited)/sizeof(int), 0);
	group_set.clear();
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (!visited[i][j]) makeGroup(i, j);
}

int check(group now) {
	int cnt = 0;
	for (int i = 0; i < 3; i++) {
		if (now.food & (1 << i)) cnt++;
	}
	return cnt;
}

bool compare(group left, group right) {
	if (left.g_power != right.g_power) return left.g_power > right.g_power;
	int cl = check(left), cr = check(right);
	if (cl != cr) return cl < cr;
	if (left.y != right.y) return left.y < right.y;
	return left.x < right.x;
}

void spread(group now) {
	if (shield[now.y][now.x]) return;
	int dir = now.g_power % 4;
	int desire = now.g_power - 1;
	power[now.y][now.x] = 1;
	int y = now.y, x = now.x;
	while (desire > 0) {
		y += dy[dir]; x += dx[dir];
		if (y < 0 || x < 0 || y >= N || x >= N) break;
		if (food[y][x] == now.food) continue;
		shield[y][x] = 1;
		if (desire > power[y][x]) {
			desire -= power[y][x] + 1;
			food[y][x] = now.food;
			power[y][x]++;
		} else {
			power[y][x] += desire;
			food[y][x] |= now.food;
			break;
		}
	}
}

void dinner() {
	fill(&shield[0][0], &shield[0][0] + sizeof(shield)/sizeof(int), 0);
	vector<group> groups[4];
	for (auto &g : group_set)
		groups[check(g)].push_back(g);
	for (int i = 1; i <= 3; i++) {
		sort(groups[i].begin(), groups[i].end(), compare);
		for (auto &g : groups[i]) spread(g);
	}
}

void calc() {
	int result[8] = { 0 };
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			result[food[i][j]] += power[i][j];
	cout << result[7] << " " << result[6] << " " << result[5] << " " << result[3] << " " << result[1] << " " << result[2] << " " << result[4] << "\n";
}

void input() {
	cin >> N >> T;
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		for (int j = 0; j < N; j++) {
			if (s[j] == 'T') food[i][j] = 4;
			else if (s[j] == 'C') food[i][j] = 2;
			else food[i][j] = 1;
		}
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> power[i][j];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	input();
	for (int i = 0; i < T; i++) {
		morning();
		lunch();
		dinner();
		calc();
	}
	return 0;
}
