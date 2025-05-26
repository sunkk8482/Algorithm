#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 신앙 음식
int food[51][51];
// 신앙심
int power[51][51];
// 좌표 정보
struct node {
	int y;
	int x;
};


// 그룹 정보
struct group {
	// 그룹이 믿는거
	int food;
	// 대표자의 y
	int y;
	// 대표자의 x
	int x;
	// 대표자의 신앙심
	int g_power;
	// 대표를 포함한 소속원들
	//vector<node> people;
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
// 방향 벡터
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int N, T;

//아침
void morning() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			power[i][j]++;
		}
	}
}

//점심

// 방문 배열
int visited[51][51];

// 그룹 정리
unordered_set<group> group_set;

// 그룹 나누기 함수
void makeGroup(int y, int x) {
	// y x부터 bfs를 시작
	// 같은 음식인 사람들 끼리 그룹 묶기

	// 현재 팀원들
	vector<node> team;

	// 현재 대표자의 정보
	int best_y = y;
	int best_x = x;
	int best_power = power[y][x];
	int now_food = food[y][x];
	queue<node> q;
	team.push_back({ y,x });
	q.push({ y,x });
	visited[y][x] = 1;
	while (!q.empty()) {
		node now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = dy[i] + now.y;
			int nx = dx[i] + now.x;
			// 범위를 안벗어나며 방문안했고 음식이 같을때
			if (ny < 0 || nx < 0 || ny >= N || nx >= N)continue;
			if (visited[ny][nx])continue;
			if (food[ny][nx] != now_food)continue;
			// 현재 대표자와 비교
			if (best_power < power[ny][nx]) {
				best_y = ny;
				best_x = nx;
				best_power = power[ny][nx];
			}
			else if (best_power == power[ny][nx]) {
				if (ny < best_y) {
					best_y = ny;
					best_x = nx;
					best_power = power[ny][nx];
				}
				else if (ny == best_y) {
					if (nx < best_x) {
						best_y = ny;
						best_x = nx;
						best_power = power[ny][nx];
					}
				}
			}
			q.push({ ny,nx });
			visited[ny][nx] = 1;
			team.push_back({ ny,nx });
		}
	}
	for (auto i : team) {
		if (i.y == best_y && i.x == best_x)continue;
		power[i.y][i.x]--;
		power[best_y][best_x]++;
	}

	group_set.insert({ now_food,best_y,best_x,power[best_y][best_x] });
}

void lunch() {
	// 방문배열 초기화
	fill(visited[0], visited[51], 0);
	// 그룹 초기화
	group_set.clear();
	// 그룹 나누기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j])continue;
			makeGroup(i, j);
		}
	}
}

// 음식 조합 확인
int check(group now) {
	int cnt = 0;
	int f = now.food;
	for (int i = 0; i < 3; i++) {
		if (f & (1 << i)) cnt++;
	}
	return cnt; // 1: 단일, 2: 이중, 3: 삼중
}

// 순서 정렬 함수
bool compare(group left, group right) {
	if (left.g_power > right.g_power) {
		return true;
	}
	else if (left.g_power == right.g_power) {
		// 왼쪽이 단일이고 오른쪽이 아닐때
		if (check(left) == 1 && check(right) != 1) {
			return true;
		}
		// 왼쪽이 이중이고 오른쪽이 삼중일때
		if (check(left) == 2 && check(right) == 3) {
			return true;
		}
		// 왼쪽과 오른쪽이 같을때
		if (check(left) == check(right)) {
			if (left.y < right.y) {
				return true;
			}
			else if (left.y == right.y) {
				if (left.x < right.x) {
					return true;
				}
			}
		}
	}
	return false;

}

// 방어 배열
int shield[51][51];

void spread(group now) {
	// 방향
	int direction = now.g_power % 4;
	// 간절함
	now.g_power--;
	// 전파자의 신앙심은 1로
	power[now.y][now.x] = 1;

	// 복사
	group temp = now;
	// 전파 시작
	while (true) {
		temp.y += dy[direction];
		temp.x += dx[direction];
		// 범위 넘으면 끝
		if (temp.y < 0 || temp.x < 0 || temp.y >= N || temp.x >= N)break;

		// 현재 위치에서 음식 비교 같으면 스킵
		if (food[temp.y][temp.x] == temp.food)continue;

		// 강한 전파
		if (temp.g_power > power[temp.y][temp.x]) {
			food[temp.y][temp.x] = temp.food;
			temp.g_power -= power[temp.y][temp.x] + 1;
			power[temp.y][temp.x]++;
			shield[temp.y][temp.x] = 1;
		}
		// 약한 전파
		else {
			food[temp.y][temp.x] |= temp.food;
			power[temp.y][temp.x] += temp.g_power;
			temp.g_power = 0;
			shield[temp.y][temp.x] = 1;
		}

		// 신앙심 0이하면 끝
		if (temp.g_power <= 0) {
			break;
		}
	}

}

// 저녁
void dinner() {
	fill(shield[0], shield[51], 0);
	// 전파할 순서 정하기
	vector < vector<group>> group_vec(4, vector<group>());
	for (auto i : group_set) {
		group_vec[check(i)].push_back(i);
	}
	for (auto i : group_vec) {
		sort(i.begin(), i.end(), compare);
	}
	
	for (auto i : group_vec) {
		for (auto j : i) {
			if (shield[j.y][j.x])continue;
			spread(j);
		}
	}
	
}

int answer[8];
void calc() {
	fill(answer, answer + 8, 0);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			answer[food[i][j]] += power[i][j];
		}
	}

	cout << answer[7] << " " << answer[6] << " " << answer[5] << " " << answer[3] << " "
		<< answer[1] << " " << answer[2] << " " << answer[4] << "\n";

}

//입력
void input() {
	cin >> N >> T;
	// 초기 음식 입력
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < N; j++) {
			if (s.at(j) == 'T') {
				food[i][j] = 4;
			}
			else if (s.at(j) == 'C') {
				food[i][j] = 2;
			}
			else {
				food[i][j] = 1;
			}
		}
	}
	// 초기 신앙심
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> power[i][j];
		}
	}

}

int main() {
	input();
	for (int i = 0; i < T; i++) {
		morning();
		lunch();
		dinner();
		calc();
	}
}

/*

N*N 책상

1행 1열 부터 N,N까지 학생 앉아있음

각 학생은 처음에 T(민트) C(초코) M(우유) 중 하나 신봉 Fij

다른 사람의 영향을 받아 초코우유 민트우유 민트초코 민트초코우유 가능

각 학생의 신앙심 Bij

T일 동안의 순서

1. 아침
Bij값에 1씩 더해짐

2. 점심
상하좌우 와 신봉이 완전 같으면 그룹 형성
대표자 : 그룹 안에 B가 가장 큰사람 동일하면 r(y)이 가장 작은 아니면 c(x)가 가장 작은
대표자가 아닌 그룹원은 1씩 대표자에게 넘김

3. 저녁
모든 그룹의 대표자 신앙 전파
단일 음식 -> 이중 조합 -> 삼중조합 순 전파
같은 그룹이라면 신앙신 높은 아니라면 y 작은 x 작은 순

전파자는 B중 1만 남기고 나머지를 간절함으로 바꿔 사용
전파 방향은 B를 4로 나눈 나머지 상하좌우

한칸씩 이동하며 전파 간절함이 0이 될때 까지
전파대상이 전파자와 신봉음식이 같다면 스킵 후 이동

다르면 전파 시작
간절함 > B
동일한 음식 신봉 전파자는 (B+1)만큼 간절함 깎임
전파 대상의 신앙심 1 증가
간절함 < B
약한 전파
전파 대상은 전파한 음식의 모든 기본음식에도 관심
즉 합친 음식
대상의 신앙심은 간절함만큼 증가

100민트 010초코 001우유

그룹{
	믿는거
	대표자 y x
	대표자 신앙심
}


*/