#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    sort(strings.begin(), strings.end(),
        [n](const string& left, const string& right) {
            if (left[n] == right[n]) {
                return left < right;  
            }

            return left[n] < right[n]; 
        });

    return strings;
}