#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "Nhap so nguyen duong: ";
    while (true) {
        cin >> s;
        if (all_of(s.begin(), s.end(), ::isdigit) && s[0] != '0') break;
        cout << "Loi: chi nhap chu so nguyen duong khong co 0 o dau. Nhap lai: ";
    }

    if (next_permutation(s.begin(), s.end())) {
        cout << "Hoan vi ke tiep: " << s << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
