/*

	8개의 톱니를 가진 톱니바퀴 각 톱니는 N or S 
	가장 왼쪽이 1번 오른쪽으로 갈수록 늘어남 1 2 3 4 까지
	톱니바퀴를 K번 회전 시계 또는 반시계


	하나가 회전하면 

	00000000  2번인덱스 6번인덱스
	00000000
	00000000
	00000000

	시계방향은 >>1
	반시계 <<1
*/
#include <iostream>
#include <string>
using namespace std;
int K;
int arr[4];
int turn[4];

enum direction
{
	CW = 1,
	CCW = -1,
	NONE = 0
};

void do_rotate()
{
	for (int i = 0; i <= 3; i++)
	{
		int num = arr[i];
		if (turn[i] == CW)
		{
			int temp = num & 0b1;
			num = num >> 1;
			num |= (temp << 7);
			arr[i] = num;
		}
		else if (turn[i] == CCW)
		{
			int temp = (num >> 7) & 0b1;
			num = num << 1;
			num |= temp;
			num &= 0b11111111;
			arr[i] = num;
		}
	}
}

void rotate(int num,int dir)
{
	turn[num] = dir;
	int idx = num;
	for (int i = idx; i > 0; i--)
	{
		if (turn[i] == NONE)continue;
		int cur = arr[i];
		int left = arr[i - 1];
		if (((cur>>1)&0b1) != ((left>>5)&0b1))
		{
			if (turn[i] == CW)turn[i - 1] = CCW;
			else turn[i - 1] = CW;
		}
		else {
			turn[i - 1] = NONE;
		}
	}
	for (int i = idx; i < 3; i++)
	{
		if (turn[i] == NONE)continue;
		int cur = arr[i];
		int right = arr[i + 1];
		if (((cur>>5)&0b1) != ((right>>1)&0b1))
		{
			if (turn[i] == CW)turn[i + 1] = CCW;
			else turn[i + 1] = CW;
		}
		else {
			turn[i + 1] = NONE;
		}
	}
	do_rotate();
	for (int i = 0; i < 4; i++) {
		turn[i] = NONE;
	}
}
void score()
{
	//n 0 s1
	int sum = 0;
	int base = 1;
	for (int i = 0; i < 4; i++) {
		int num = arr[i];
		if (num >> 7)
		{
			sum += base;
		}
		base *= 2;
	}
	cout << sum;
}

int main()
{
	for (int i = 0; i < 4; i++)
	{
		int bin = 0;
		string s;
		cin >> s;
		int dec = 1;
		for (int j = s.size() - 1; j >= 0;j--) {
			char b = s.at(j);
			bin += (b - '0') * dec;
			dec *= 2;
		}
		arr[i] = bin;
	}
	cin >> K;
	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		rotate(a-1, b);
	}
	score();
}