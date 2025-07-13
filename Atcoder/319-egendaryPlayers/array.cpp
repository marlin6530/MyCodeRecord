#include <iostream>
#include <string>
using namespace std;

int main() {
    string players[10] = {
        "tourist",
        "ksun48",
        "Benq",
        "Um_nik",
        "apiad",
        "Stonefeang",
        "ecnerwala",
        "mnbvmar",
        "newbiedmy",
        "semiexp"
    };
    int score[N] = {
        3858,
        3679,
        3658,
        3648,
        3638,
        3630,
        3613,
        3555,
        3516,
        3481
    };

    string name;
    while (cin >> name) {
        for (int i = 0; i < 10; ++i) {
            if (name == players[i]) {
                cout << score[i] << '\n';
                break;
            }
        }
    }
    return 0;
}
