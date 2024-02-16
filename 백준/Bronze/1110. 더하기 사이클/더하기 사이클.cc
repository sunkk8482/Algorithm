#include <iostream>
 
using namespace std;
 
int main() {
 
	int i, N;

	cin >> i;
 
	N = i;
 	int cnt = 0;
	do {
		N = (N % 10) * 10 + ((N / 10) + (N % 10)) % 10;
		cnt++;
	} while (i != N);
 
	cout << cnt;
	return 0;
}