#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Student {
    string name;
    int kor, eng, mat;
};

bool compare(Student a, const Student b) {
    if(a.kor == b.kor) {
        if(a.eng == b.eng) {
            if(a.mat == b.mat) {
                return a.name < b.name;
            }
            else return a.mat > b.mat;
        }
        else return a.eng < b.eng;
    }
    else return a.kor > b.kor;
}

int main(void) {
    int n;
    scanf("%d", &n);

    vector<Student> list(n);
    for(int i = 0; i < n; i++) {
        cin >> list[i].name >> list[i].kor >> list[i].eng >> list[i].mat;
    }

    sort(list.begin(), list.end(), compare);
    for(int i = 0; i < n; i++) {
        cout << list[i].name << "\n";
    }
    return 0;
}