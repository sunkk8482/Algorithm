#include <iostream>
#include <string>
#include <string.h>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Trie {
    int countA, countB;
    Trie* nodes[26];

    Trie() {
        countA = 0;
        countB = 0;
        for (int i = 0; i < 26; i++) {
            nodes[i] = nullptr;
        }
    }

    ~Trie() {
        for (int i = 0; i < 26; i++) {
            if (nodes[i] != nullptr) {
                delete nodes[i];
            }
        }
    }

    void add(const char* str) {
        if (*str == '\0') return;
        int index = *str - 'a';
        if (nodes[index] == nullptr) {
            nodes[index] = new Trie();
        }
        nodes[index]->countA++;
        nodes[index]->add(str + 1);
    }

    void addReverse(const char* str, int size) {
        if (size <= 0) return;
        int index = *str - 'a';
        if (nodes[index] == nullptr) {
            nodes[index] = new Trie();
        }
        nodes[index]->countB++;
        nodes[index]->addReverse(str - 1, size - 1);
    }

    void remove(const char* str) {
        if (*str == '\0') return;
        int index = *str - 'a';
        if (nodes[index] != nullptr) {
            nodes[index]->countA--;
            nodes[index]->remove(str + 1);
        }
    }

    void removeReverse(const char* str, int size) {
        if (size <= 0) return;
        int index = *str - 'a';
        if (nodes[index] != nullptr) {
            nodes[index]->countB--;
            nodes[index]->removeReverse(str - 1, size - 1);
        }
    }

    int find(const char* str, int size) {
        if (size <= 0) return countA;
        int index = *str - 'a';
        if (nodes[index] == nullptr) return 0;
        return nodes[index]->find(str + 1, size - 1);
    }

    int findReverse(const char* str, int size) {
        if (size <= 0) return countB;
        int index = *str - 'a';
        if (nodes[index] == nullptr) return 0;
        return nodes[index]->findReverse(str - 1, size - 1);
    }
};

int main() {
    Trie* root = new Trie();
    int N;
    cin >> N;

    string command, str;
    char type;

    for (int i = 0; i < N; i++) {
        cin >> command;

        if (command == "add") {
            cin >> type >> str;
            if (type == 'A') {
                root->add(str.c_str());
            }
            else if (type == 'B') {
                root->addReverse(str.c_str() + str.size() - 1, str.size());
            }
        }
        else if (command == "delete") {
            cin >> type >> str;
            if (type == 'A') {
                root->remove(str.c_str());
            }
            else if (type == 'B') {
                root->removeReverse(str.c_str() + str.size() - 1, str.size());
            }
        }
        else if (command == "find") {
            cin >> str;
            int total = 0;
            int n = str.size();

            int foundA[1010] = { 0 };
            int foundB[1010] = { 0 };

            Trie* tempA = root;
            Trie* tempB = root;

            for (int j = 0; j < n; j++) {
                foundA[j] = tempA->countA;
                if (tempA->nodes[str[j] - 'a'] == nullptr) break;
                tempA = tempA->nodes[str[j] - 'a'];
            }

            for (int j = n - 1; j >= 0; j--) {
                foundB[j] = tempB->countB;
                if (tempB->nodes[str[j] - 'a'] == nullptr) break;
                tempB = tempB->nodes[str[j] - 'a'];
            }

            for (int j = 1; j < n; j++) {
                total += foundA[j] * foundB[j - 1];
            }

            cout << total << endl;
        }
    }

    delete root;
    return 0;
}
