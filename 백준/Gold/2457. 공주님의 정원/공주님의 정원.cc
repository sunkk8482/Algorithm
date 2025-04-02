#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;

struct flower {
	int open_month;
	int open_day;
	int close_month;
	int close_day;
};


// 피는 날짜가 빠른게 앞에 오도록
// 날짜가 같으면 빨리지는게 앞에 오도록 
bool compare(flower a, flower b) {
	// a가 앞달에 피면 당연히 true
	if (a.open_month < b.open_month) {
		return true;
	}
	// 같은 달에 피면
	else if(a.open_month==b.open_month){
		if (a.open_day < b.open_day) {
			return true;
		}
		// 여긴 같은 날에 피는거임
		else if (a.open_day == b.open_day) {
			if (a.close_month < b.close_month) {
				return true;
			}
			else if (a.close_month == b.close_month) {
				if (a.close_day < b.close_day) {
					return true;
				}
			}
		}
	}
	// 여기 부터는 a가 늦게 피는거임
	return false;

}

// 3월 1일 부터 11월 30일까지 최소한으로 선택
// 가능한 꽃들 중에 가장 늦게 끝나는거 선택
// 12월 1일에 지는게 최대 마지노선
vector<flower> v;

int main() {
	cin >> N;

	//피는 날짜 지는 날짜
	for (int i = 0; i < N; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		v.push_back({ a,b,c,d });
	}
	sort(v.begin(), v.end(), compare);

	// 현재 꽃의 피는 날
	int now_month = 3;
	int now_day = 1;

	// 현재 꽃이 지는 날
	int end_month = 0;
	int end_day = 0;

	int answer = 0;

	bool err = false;

	for (auto i : v) {
		// 시작 날짜가 같거나 작으면서 지는 날짜가 가장 뒤인 꽃 선택
		if (i.open_month < now_month || (i.open_month==now_month && i.open_day <= now_day)) {
			if (i.close_month > end_month || (i.close_month==end_month && i.close_day > end_day)) {
				end_month = i.close_month;
				end_day = i.close_day;
			}
			if (end_month == 12) {  
				answer++;
				break;
			}
		}//만약 시작날짜가 지금보다 뒤라면 체인지 시작
		else {
			if (end_month < i.open_month || (end_month==i.open_month && end_day < i.open_day)) {
				err = true;
				break;
				//이건 이제 불가능
			}
			answer++;
			now_month = end_month;
			now_day = end_day;
			end_month = i.close_month;
			end_day = i.close_day;
			if (end_month == 12) {
				answer++;
				break;
			}
		}
	}
	if (end_month < 12) {
		err = true;
	}
	if (err) {
		cout << 0;
		return 0;
	}
	cout << answer;
	
}