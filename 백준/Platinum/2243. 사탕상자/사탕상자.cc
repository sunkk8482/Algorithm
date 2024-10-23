#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int n; // 입력 데이터 개수
vector<int> tree; // 세그먼트 트리 저장 배열
int S; // 리프 노드 시작 인덱스

void init(); // 트리 초기화
int query(int left, int right, int node, int target); // K번째 수 찾기
void update(int left, int right, int node, int target, long long diff); // 값 갱신

int main() {
    ios::sync_with_stdio(false); // 입력 속도 최적화
    cin.tie(nullptr); // 입출력 묶음 해제

    cin >> n;
    tree.resize(4000000); // 세그먼트 트리 배열 초기화
    S = 1;
    while (S < n) {
        S *= 2; // 가장 가까운 2의 거듭제곱 찾기
    }

    for (int i = 0; i < n; ++i) {
        int A;
        cin >> A;

        if (A == 1) {
            int B;
            cin >> B;
            int ret = query(1, 1000000, 1, B);
            update(1, 1000000, 1, ret, -1); // 값을 감소
            cout << ret << '\n';
        }
        else if (A == 2) {
            int B, C;
            cin >> B >> C;
            update(1, 1000000, 1, B, C); // 값 갱신
        }
    }

    return 0;
}

// 트리 초기화 (bottom-up 방식)
void init() {
    // 리프 노드 초기화
    for (int i = 0; i < n; ++i) {
        tree[S + i] = 0;
    }
    // 내부 노드 초기화 (자식 노드의 합 계산)
    for (int i = S - 1; i > 0; --i) {
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
}

// K번째 수 찾기 (쿼리)
int query(int left, int right, int node, int target) {
    // 리프 노드 도달 시 해당 위치 반환
    if (left == right) {
        return left;
    }

    int mid = (left + right) / 2;
    // 왼쪽 자식 노드가 target 이상인 경우
    if (tree[node * 2] >= target) {
        return query(left, mid, node * 2, target);
    }
    // 오른쪽 자식 노드로 이동하며 target 갱신
    else {
        return query(mid + 1, right, node * 2 + 1, target - tree[node * 2]);
    }
}

// 값 갱신 (update)
void update(int left, int right, int node, int target, long long diff) {
    // 연관 없는 범위는 무시
    if (target < left || target > right) {
        return;
    }

    // 연관된 노드 갱신
    tree[node] += diff;
    if (left != right) { // 내부 노드라면 자식 노드도 갱신
        int mid = (left + right) / 2;
        update(left, mid, node * 2, target, diff);
        update(mid + 1, right, node * 2 + 1, target, diff);
    }
}
