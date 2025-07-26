#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "Nhap chuoi: ";
    getline(cin, s);

    long long tong = 0;
    string soTam = "";

    for (char c : s) {
        if (isdigit(c)) {
            soTam += c;
        } else if (!soTam.empty()) {
            tong += stoll(soTam);
            soTam = "";
        }
    }

    // Cộng số cuối nếu có
    if (!soTam.empty()) {
        tong += stoll(soTam);
    }

    cout << "Tong cac so trong chuoi: " << tong << endl;
    return 0;
}
