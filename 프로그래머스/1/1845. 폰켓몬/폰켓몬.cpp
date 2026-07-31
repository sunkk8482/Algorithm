#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    unordered_set<int> types(nums.begin(), nums.end());

    return min(
        static_cast<int>(types.size()),
        static_cast<int>(nums.size() / 2)
    );
}