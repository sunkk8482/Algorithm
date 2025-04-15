#include <string>
#include <vector>
using namespace std;
vector<int> solution(int n, int s) {
    if (s < n)
        return {-1};
    vector<int> ans(n, s / n);
    for (int i = n - 1; i >= n - (s -( (s / n) * n)); i--)
        ans[i]++;
    return ans;
}