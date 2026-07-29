#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (auto command : commands)
    {
        vector<int> temp;
        for (int i = command[0]-1; i < command[1];i++)
        {
            temp.push_back(array[i]);
        }
        sort(temp.begin(), temp.end());
        answer.push_back(temp[command[2]-1]);
    }
    
    return answer;
}

int main() {
    solution({ 1,5,2,6,3,7,4 }, { {2,5,3},{4,4,1},{1,7,3} });
}