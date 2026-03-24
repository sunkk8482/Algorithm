#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;
using ull = unsigned long long;
#define base 131

string s;
int K, M;
unordered_map<ull, int> um;


int main()
{
	cin >> s >> K >> M;

	// 길이 K이상 동일한 패턴 M 반복시 1
	// K=3이라할때 1011 1011 1011 이면 사실상 101도 반복 그냥 K만 확인
	ull power = 1;
	// power는 base의 K제곱
	for (int i = 0; i < K; i++) {
		power *= base;
	}
	
	// 첫해시값 생성
	ull hashValue = 0;
	for (int i = 0; i < K; i++) {

		hashValue = (hashValue * base) + (unsigned char)s[i] + 1;
	}
	um[hashValue]++;

	// 반복
	for (int i = K; i < s.size(); i++)
	{
		hashValue = (hashValue * base) + (unsigned char)s[i] + 1;
		hashValue -= (power * ((unsigned char)s[i - K] + 1));
		um[hashValue]++;
		if (um[hashValue] >= M) {
			cout << 1;
			return 0;
		}
	}
	cout << 0;
	return 0;
}
