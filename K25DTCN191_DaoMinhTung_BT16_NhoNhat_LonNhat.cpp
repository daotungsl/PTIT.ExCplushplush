#include <iostream>
#include <string>
using namespace std;

string findSmallest(int m, int s) {
    if ((s == 0 && m > 1) || s > 9 * m) return "-1";
    
    string res(m, '0');
    int sum = s;

    for (int i = m - 1; i >= 0; --i) {
        int digit = max(0, sum - 9 * i);
        if (i == m - 1 && digit == 0 && m != 1) digit = 1;
        res[i] = digit + '0';
        sum -= digit;
    }

    return res;
}

string findLargest(int m, int s) {
    if ((s == 0 && m > 1) || s > 9 * m) return "-1";

    string res(m, '0');
    int sum = s;

    for (int i = 0; i < m; ++i) {
        int digit = min(9, sum);
        res[i] = digit + '0';
        sum -= digit;
    }

    return res;
}

int main() {
    int m, s;
    cout << "Nhap so chu so m va tong chu so s: ";
    while (true) {
        cin >> m >> s;
        if (m >= 1 && m <= 100 && s >= 0 && s <= 900) break;
        cout << "Loi: 1 <= m <= 100, 0 <= s <= 900. Nhap lai: ";
    }

    string smallest = findSmallest(m, s);
    string largest = findLargest(m, s);

    cout << "So nho nhat: " << smallest << endl;
    cout << "So lon nhat: " << largest << endl;

    return 0;
}
