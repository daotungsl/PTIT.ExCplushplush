#include <iostream>
#include <cmath>
using namespace std;

// Hàm kiểm tra số nguyên tố
bool isPrime(int number) {
    if (number < 2) return false;
    for (int i = 2; i <= sqrt(number); ++i) {
        if (number % i == 0) return false;
    }
    return true;
}

// Hàm liệt kê các số có đúng 3 ước số
void listNumbersWithThreeDivisors(int n) {
    for (int i = 2; i * i <= n; ++i) {
        if (isPrime(i)) {
            cout << i * i << " ";
        }
    }
    cout << endl;
}

int main() {
    int testCases;
    cout << "Nhap so luong bo test: ";
    while (true) {
        cin >> testCases;
        if (testCases >= 1 && testCases <= 100) break;
        cout << "Loi. So bo test phai tu 1 den 100. Nhap lai: ";
    }

    while (testCases--) {
        int n;
        cout << "Nhap so tu nhien n: ";
        while (true) {
            cin >> n;
            if (n >= 1 && n <= 1000000) break;
            cout << "Loi. n phai trong khoang 1 den 10^6. Nhap lai: ";
        }
        listNumbersWithThreeDivisors(n);
    }
    return 0;
}
