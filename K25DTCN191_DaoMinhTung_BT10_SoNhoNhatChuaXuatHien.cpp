#include <iostream>
#include <unordered_set>
using namespace std;

int findSmallestMissingPositive(int arr[], int n) {
    unordered_set<int> positives;
    for (int i = 0; i < n; ++i) {
        if (arr[i] > 0) {
            positives.insert(arr[i]);
        }
    }

    for (int i = 1; i <= n + 1; ++i) {
        if (positives.find(i) == positives.end()) {
            return i;
        }
    }

    return n + 1;
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
        cout << "Nhap so luong phan tu: ";
        while (true) {
            cin >> n;
            if (n >= 1 && n <= 1000000) break;
            cout << "Loi. So phan tu phai tu 1 den 10^6. Nhap lai: ";
        }

        int* arr = new int[n];
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        int result = findSmallestMissingPositive(arr, n);
        cout << result << endl;

        delete[] arr;
    }

    return 0;
}
