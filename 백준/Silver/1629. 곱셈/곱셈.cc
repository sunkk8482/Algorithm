#include <iostream>

using namespace std;

#define ll long long 

ll func(ll a, ll b, ll c) {
	if (b == 1) return a % c;
	ll ret = func(a, b / 2, c);
	ret = ret * ret % c;
	if (b % 2 == 0)return ret;
	return ret * a % c;
}

int main() {
	ll a, b, c;
	cin >> a >> b >> c;
	cout << func(a, b, c);
}
