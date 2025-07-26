#include <iostream>
#include <cctype>
using namespace std;

void convertLetterCase(char character) {
    if (isupper(character)) {
        cout << (char)tolower(character);
    } else if (islower(character)) {
        cout << (char)toupper(character);
    } else {
        cout << "Phan tu khong hop le";
    }
}

int main() {
    int testCases;
    cout << "Nhap so bo test: ";
    while (true) {
        cin >> testCases;
        if (testCases > 0 && testCases <= 100) break;
        cout << "Loi: so bo test phai nam trong khoang 1-100. Nhap lai: ";
    }

    while (testCases--) {
        char inputChar;
        cout << "Nhap mot ky tu: ";
        cin >> inputChar;
        convertLetterCase(inputChar);
        cout << endl;
    }

    return 0;
}
