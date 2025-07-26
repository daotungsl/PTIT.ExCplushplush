#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'o' || c == 'y' || c == 'e' || c == 'u' || c == 'i');
}

string processString(const string& input) {
    string result;
    for (char c : input) {
        char lowerChar = tolower(c);
        if (!isVowel(lowerChar)) {
            result += '.';
            result += lowerChar;
        }
    }
    return result;
}

int main() {
    string s;
    cout << "Nhap xau: ";
    while (true) {
        cin >> s;
        if (s.size() <= 100) break;
        cout << "Loi: Do dai xau khong qua 100 ky tu. Nhap lai: ";
    }

    string processed = processString(s);
    cout << processed << endl;

    return 0;
}
