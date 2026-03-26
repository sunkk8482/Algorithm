#include <iostream>
#include <queue>

using namespace std;

enum Road {
	Block = 0,
	Free = 1,
};

int arr[5][4][5][5]; // n번째 몇번회전 배열
int cube[5][5][5];

void MakeArr()
{
	for (int i = 0; i < 5; i++) {
		for (int j = 1; j < 4; j++) {
			for (int k = 0; k < 5; k++) {
				for (int l = 0; l < 5; l++) {
					arr[i][j][l][4 - k] = arr[i][j - 1][k][l];
				}
			}
		}
	}
}

int dfsVisited[5];
int dz[6] = { 0,0,0,0,-1,1 };
int dy[6] = { -1,1,0,0,0,0 };
int dx[6] = { 0,0,-1,1 ,0,0 };

struct node
{
	int z;
	int y;
	int x;
};

int bfsVisited[5][5][5];

void init()
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				bfsVisited[i][j][k] = 0;
			}
		}
	}
}

bool operator==(node left, node right)
{
	if ((left.z == right.z) && (left.y == right.y) && (left.x == right.x))return true;
	else return false;
}

int bfs(int n)
{
	node departure;
	node destination;
	switch (n) {
	case 0:
		departure = { 0,0,0 };
		destination = { 4,4,4 };
		break;
	case 1:
		departure = { 0,0,4 };
		destination = { 4,4,0 };
		break;
	case 2:
		departure = { 0,4,0 };
		destination = { 4,0,4 };
		break;
	case 3:
		departure = { 0,4,4 };
		destination = { 4,0,0 };
		break;
	default:
		departure = { -1,-1,-1 };
		destination = { -1,-1,-1 };
	}

	if (departure.z == -1) {
		cout << "error";
		exit(0);
	}

	if (cube[departure.z][departure.y][departure.x] == Block) {
		return -1;
	}
	if (cube[destination.z][destination.y][destination.x] == Block) {
		return -1;
	}

	queue<node> q;
	q.push(departure);
	bfsVisited[departure.z][departure.y][departure.x] = 1;

	while (!q.empty())
	{
		node now = q.front();
		q.pop();
		if (now == destination)
		{
			return bfsVisited[now.z][now.y][now.x] - 1;
		}
		for (int i = 0; i < 6; i++) {
			int nz = now.z + dz[i];
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if (nz < 0 || ny < 0 || nx < 0 || nz >= 5 || nx >= 5 || ny >= 5) continue;
			if (bfsVisited[nz][ny][nx] != 0)continue;
			if (cube[nz][ny][nx] == Block)continue;
			q.push({ nz,ny,nx });
			bfsVisited[nz][ny][nx] = bfsVisited[now.z][now.y][now.x] + 1;
		}
	}
	return -1;

}


int answer = -1;

void dfs(int depth, int index)
{
	if (answer == 12)
	{
		return;
	}
	// 일단 자기거 회전 해서 삽입
	for (int rotate = 0; rotate < 4; rotate++)
	{
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++)
			{
				cube[depth][i][j] = arr[index][rotate][i][j];
			}
		}
		// 이놈 회전해봤자 의미 없으면 넘어감
		if (depth == 0 || depth == 4)
		{
			if (cube[depth][0][0] == Block && cube[depth][0][4] == Block && cube[depth][4][0] == Block && cube[depth][4][4] == Block)
			{
				continue;
			}
		}
		if (depth == 4)
		{
			for (int i = 0; i < 4; i++)
			{
				init();
				int ret = bfs(i);
				if (ret == 12)
				{
					answer = 12;
					return;
				}
				if (ret != -1)
				{
					if (answer == -1)
					{
						answer = ret;
					}
					else
					{
						answer = min(answer, ret);
					}
				}
			}
			continue;
		}

		// 다음꺼 진행
		for (int i = 0; i < 5; i++)
		{
			if (dfsVisited[i])continue;
			dfsVisited[i] = 1;
			dfs(depth + 1, i);
			dfsVisited[i] = 0;
		}
	}
}


int main()
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				cin >> arr[i][0][j][k];
			}
		}
	}

	MakeArr();

	for (int i = 0; i < 5; i++)
	{
		dfsVisited[i] = 1;
		dfs(0, i);
		dfsVisited[i] = 0;
		if (answer == 12)
		{
			cout << 12;
			return 0;
		}
	}
	cout << answer;

}