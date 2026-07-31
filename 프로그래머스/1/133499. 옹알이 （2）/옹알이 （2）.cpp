#include <string>
#include <vector>

using namespace std;

string li[4] = { "aya", "ye", "woo", "ma" };

int solution(vector<string> babbling) {
    int answer = 0;

    for (const string& word : babbling) {
        size_t pos = 0;
        int previous = -1;
        bool valid = true;

        while (pos < word.size()) {
            bool found = false;

            for (int j = 0; j < 4; j++) {
                if (word.compare(pos, li[j].size(), li[j]) == 0) {
                    if (previous == j) {
                        valid = false;
                        break;
                    }

                    previous = j;
                    pos += li[j].size();
                    found = true;
                    break;
                }
            }
            if (!found) {
                valid = false;
                break;
            }
        }

        if (valid) {
            answer++;
        }
    }

    return answer;
}