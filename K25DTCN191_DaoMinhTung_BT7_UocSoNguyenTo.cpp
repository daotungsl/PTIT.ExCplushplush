#include <iostream>
#include <cmath>
using namespace std;

// Hàm kiểm tra số nguyên tố
bool isPrime(long long number) {
    if (number < 2) return false;
    for (long long i = 2; i <= sqrt(number); ++i) {
        if (number % i == 0) return false;
    }
    return true;
}

// Hàm in ra các ước số nguyên tố của n
void printPrimeDivisors(long long n) {
    for (long long i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0 && isPrime(i)) {
            cout << i << " ";
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 1 && isPrime(n)) {
        cout << n;
    }
    cout << endl;
}

int main() {
    int testCases;
    cout << "Nhap so bo test: ";
    while (true) {
        cin >> testCases;
        if (testCases >= 1 && testCases <= 100) break;
        cout << "Loi: So bo test phai tu 1 den 100. Nhap lai: ";
    }

    while (testCases--) {
        long long n;
        cout << "Nhap n: ";
        while (true) {
            cin >> n;
            if (n >= 2 && n <= 10000000000LL) break;
            cout << "Loi: n phai tu 2 den 10^10. Nhap lai: ";
        }
        printPrimeDivisors(n);
    }

    return 0;
}
