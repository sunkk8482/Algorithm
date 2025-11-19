/*

길이가 N인 컨베이어 
2N인 벨트

벨트는 2N개의 칸 1번부터 2N까지 번호

벨트는 회전하면 하나씩 밀림 

내구도가있음 1번이 올리는 위치 N이 내리는 위치


*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
vector<pair<int,bool>> belt;

void input()
{
	cin >> N >> K;
	for (int i = 0; i < 2 * N; i++) {
		int a;
		cin >> a;
		belt.push_back({a,false});
	}
}

void play()
{
	int robotcnt = 0;
	int answer = 1;
	int cnt = 0;
	while (cnt < K)
	{
		//1. 벨트가 한칸회전
		rotate(belt.begin(), belt.end() - 1, belt.end());
		if (belt[N - 1].second)
		{
			belt[N - 1].second = false;
		}


		//	2. 올라간 순서대로 로봇 한칸 이동 혹은 가만히
		//	이동하려는 칸에 로봇이 없어야하고 내구도 1이상이어야함
		for (int i= N - 1; i >= 0; i--)
		{
			if (belt[i].second)
			{
				if (belt[i + 1].second == false && belt[i + 1].first >= 1)
				{
					belt[i].second = false;
					belt[i + 1].second = true;
					belt[i + 1].first--;
					if (belt[i + 1].first == 0)
					{
						cnt++;
					}
				}
			}
		}
		if (belt[N - 1].second)
		{
			belt[N - 1].second = false;
		}


		//	3. 올리는 위치에 내구도가 0이 아니라면 로봇 올림
		if (belt[0].first != 0)
		{
			belt[0].second = true;
			belt[0].first--;
			if (belt[0].first == 0)
			{
				cnt++;
			}
		}

		if (cnt >= K)
		{
			break;
		}
		answer++;
	}
	cout << answer;

}
int main()
{
	input();
	play();
}