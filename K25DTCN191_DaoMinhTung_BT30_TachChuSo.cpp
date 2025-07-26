#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string input;
    cout << "Nhap chuoi: ";
    getline(cin, input);

    string chu = "", so = "";

    for (char c : input) {
        if (isalpha(c))
            chu += c;
        else if (isdigit(c))
            so += c;
        // Bỏ qua ký tự khác
    }

    sort(chu.begin(), chu.end());
    sort(so.begin(), so.end());

    cout << "Chuoi sau khi sap xep: " << chu + so << endl;

    return 0;
}
