#include <iostream>
#include <stack>
#include <vector>

using namespace std;

stack<int> st;

int ans[1000001];
int arr[1000001];

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = N - 1; i >= 0; i--) {
		if (st.empty()) {
			ans[i] = -1;
			st.push(arr[i]);
		}
		else {
			while (st.top() <= arr[i]) {
				st.pop();
				if (st.empty()) {
					break;
				}
			}
			if (st.empty()) {
				ans[i] = -1;
				st.push(arr[i]);
			}
			else {
				ans[i] = st.top();
				st.push(arr[i]);
			}
		}
	}
	for (int i = 0; i < N;i++) {
		cout << ans[i] << " ";
	}

}