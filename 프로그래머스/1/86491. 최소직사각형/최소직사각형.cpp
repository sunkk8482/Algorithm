#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int maxV = 0;
    int maxH = 0;
    for (auto i : sizes)
    {
        if (i[0] < i[1])
        {
            swap(i[0], i[1]);
        }
        maxV= max(maxV, i[0]);
        maxH= max(maxH, i[1]);
    }
    return maxV*maxH;
}

int main()
{
    int a = solution({ {60,50},{30,70},{60,30},{80,40} });
}