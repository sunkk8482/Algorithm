#include <iostream>

using namespace std;

int main() {
    string st;
    cin >> st;
    string arr[1001];
    int length = st.size();
    for (int i = 0; i < length; i++) {
        arr[i] = st.substr(i, length);
    }
    for (int i = 0; i < length; i++) {
        for (int j = i; j < length; j++) {
            if (arr[j] < arr[i]) {
                string tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }

    for (int i = 0; i < length; i++) {
        cout << arr[i] << '\n';
    }
}