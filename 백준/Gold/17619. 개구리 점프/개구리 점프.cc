#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[100001];

struct node {
	int x1;
	int x2;
	int num;
}v[100001];

int N, Q;
bool cmp(const node& a, const node& b) {
    return a.x1 < b.x1;
}
int find(int tar) {
 	if (arr[tar] == tar)return tar;
	int ret = find(arr[tar]);
	arr[tar] = ret;
	return ret;
}

void setUnion(int a, int b) {
	int t1 = find(a);
	int t2 = find(b);
	arr[t1] = t2;
}


int main() {
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        arr[i] = i;
        cin >> v[i].x1 >> v[i].x2;
        int y; cin >> y;
        v[i].num = i;
    }
    sort(v + 1, v + n + 1, cmp);

    int idx = 1, end = v[1].x2;
    for (int i = 2; i <= n; i++) {
        if (v[i].x1 <= end) {
            if (v[i].x2 <= end) setUnion(v[idx].num, v[i].num);
            else {
                setUnion(v[idx].num, v[i].num);
                idx = i, end = v[i].x2;
            }
        }
        else {
            idx = i, end = v[i].x2;
        }
    }

    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        if (find(a) == find(b)) cout << "1\n";
        else cout << "0\n";
    }
    return 0;
}