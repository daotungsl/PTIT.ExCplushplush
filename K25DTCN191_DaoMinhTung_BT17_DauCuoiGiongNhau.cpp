#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int countSubstringsWithSameEnds(const string& s) {
    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }

    int total = 0;
    for (auto& entry : freq) {
        int f = entry.second;
        total += f * (f - 1) / 2;
    }

    total += s.length();  // Chuỗi độ dài 1
    return total;
}

int main() {
    int t;
    cout << "Nhap so bo test: ";
    while (true) {
        cin >> t;
        if (t >= 1 && t <= 100) break;
        cout << "Loi: 1 <= t <= 100. Nhap lai: ";
    }

    cin.ignore();  // Xóa '\n' sau số lượng test

    while (t--) {
        string s;
        cout << "Nhap xau ky tu: ";
        while (true) {
            getline(cin, s);
            if (!s.empty() && s.length() <= 1000) break;
            cout << "Loi: Do dai xau tu 1 den 1000 ky tu. Nhap lai: ";
        }

        int result = countSubstringsWithSameEnds(s);
        cout << "So xau con thoa man la: " << result << endl;
    }

    return 0;
}
