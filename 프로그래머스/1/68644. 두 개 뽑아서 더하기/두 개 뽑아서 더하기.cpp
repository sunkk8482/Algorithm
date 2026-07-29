#include <string>
#include <vector>
#include <set>
using namespace std;

set<int> vsum;

void comb(int depth, int next, vector<int> numbers, int r,int sum)
{
    if (depth == r)
    {
        vsum.insert(sum);
        return;
    }
    for (int i = next; i < numbers.size(); i++)
    {
        comb(depth + 1, i + 1, numbers, r, sum+numbers[i]);
    }
}

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    comb(0, 0, numbers, 2, 0);
    for (auto i : vsum)
    {
        answer.push_back(i);
    }
    return answer;
}

int main()
{
    solution({ 2,1,3,4,1 });
}
