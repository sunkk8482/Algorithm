#include <vector>
#include <iostream>
using namespace std;

bool is_prime(int n)
{
    int a = 0;
    if (n == 1)return false;
    for (int i = 1; i * i <= n; i++) {
        if (i * i == n)a++;
        else if (n % i == 0)a += 2;
    }
    if (a == 2)return true;
    else return false;

}
int ans = 0;
int r = 3;
void comb(int next, vector<int> nums,int depth,int sum)
{
    if (depth == r)
    {
        if (is_prime(sum))ans++;
        return;
    }
    for (int i = next; i < nums.size(); i++) {
        comb(i + 1, nums, depth + 1,sum+nums[i]);
    }
}

int solution(vector<int> nums) {
    for (int i = 0; i < nums.size(); i++) {
        comb(i + 1, nums, 1, nums[i]);
    }
    return ans;
}