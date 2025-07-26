#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int findMinimumDifference(int arr[], int n) {
    sort(arr, arr + n);  // Sắp xếp tăng dần

    int minDiff = INT_MAX;
    for (int i = 1; i < n; ++i) {
        minDiff = min(minDiff, arr[i] - arr[i - 1]);
    }
    return minDiff;
}

int main() {
    int testCases;
    cout << "Nhap so luong bo test: ";
    while (true) {
        cin >> testCases;
        if (testCases >= 1 && testCases <= 10) break;
        cout << "Loi. So bo test phai tu 1 den 10. Nhap lai: ";
    }

    while (testCases--) {
        int n;
        cout << "Nhap so phan tu: ";
        while (true) {
            cin >> n;
            if (n >= 2 && n <= 100000) break;
            cout << "Loi. So phan tu phai >= 2 va <= 10^5. Nhap lai: ";
        }

        int* arr = new int[n];
        for (int i = 0; i < n; ++i) {
            while (true) {
                cin >> arr[i];
                if (arr[i] >= 0 && arr[i] <= 1000000000) break;
                cout << "Loi. Phan tu khong am va <= 10^9. Nhap lai: ";
            }
        }

        int result = findMinimumDifference(arr, n);
        cout << result << endl;

        delete[] arr;
    }

    return 0;
}
