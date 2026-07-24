#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> temp = arr;
    sort(temp.begin(), temp.end());
    arr.erase(find(arr.begin(),arr.end(),temp[0]));
    if (arr.size() == 0)
    {
        arr.push_back(-1);
    }
    return arr;
}