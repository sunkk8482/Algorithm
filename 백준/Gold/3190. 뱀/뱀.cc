#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

int N, K,L;

int arr[102][102];

unordered_map<int, char> turn;
list<pair<int, int>> snake;

enum Direction {
	Up = 0,
	Right = 1,
	Down = 2,
	Left = 3,
};

enum Game {
	body=1,
	apple=2,
};

Direction currentDirection = Right;

void rotate(int value)
{
	int temp = currentDirection;
	temp += value;
	if (temp == -1)temp = Left;
	else if (temp == 4)temp = Up;
	currentDirection = (Direction)temp;
}

pair<int, int> GetNextPoint(pair<int,int> current)
{
	pair<int, int> ret;
	ret = current;
	switch (currentDirection) {
	case Up:
		ret.first--;
		break;
	case Right:
		ret.second++;
		break;
	case Down:
		ret.first++;
		break;
	case Left:
		ret.second--;
		break;
	}
	return ret;
}

void play()
{
	int time = 1;
	while (1)
	{
		if (turn[time-1] != 0)
		{
			if (turn[time-1] == 'D')rotate(1);
			else rotate(-1);
		}
		//먼저 뱀은 몸길이를 늘려 머리를 다음칸에 위치시킨다.
		pair<int, int> nextPoint = GetNextPoint(snake.back());
		snake.push_back(nextPoint);
		//만약 벽이나 자기자신의 몸과 부딪히면 게임이 끝난다.
		if (nextPoint.first == 0 || nextPoint.second == 0 || nextPoint.first==N+1||nextPoint.second==N+1) break;
		if (arr[nextPoint.first][nextPoint.second] == body) break;

		//만약 이동한 칸에 사과가 있다면, 그 칸에 있던 사과가 없어지고 꼬리는 움직이지 않는다.
		if (arr[nextPoint.first][nextPoint.second] == apple)
		{
			arr[nextPoint.first][nextPoint.second] = 0;
		}
		//만약 이동한 칸에 사과가 없다면, 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다.즉, 몸길이는 변하지 않는다.
		else
		{
			arr[snake.front().first][snake.front().second] = 0;
			snake.pop_front();
		}
		arr[nextPoint.first][nextPoint.second] = body;
		time++;
	}
	cout << time;
}

int main()
{
	cin >> N;
	cin >> K;
	snake.push_back({ 1,1 });
	arr[1][1] = body;
	for (int i = 0; i < K; i++) {
		int y, x;
		cin >> y >> x;
		arr[y][x] = apple;
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		int t; char c;
		cin >> t >> c;
		turn[t] = c;
	}
	play();
}