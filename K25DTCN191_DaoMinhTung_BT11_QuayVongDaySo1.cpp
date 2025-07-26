#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotateLeft(vector<int>& arr, int d) {
    int n = arr.size();
    d %= n;  // Ğ? phòng d > n
    reverse(arr.begin(), arr.begin() + d);       // Ğ?o ph?n d?u
    reverse(arr.begin() + d, arr.end());         // Ğ?o ph?n sau
    reverse(arr.begin(), arr.end());             // Ğ?o toàn b?
}

int main() {
    int testCases;
    cout << "Nhap so luong bo test: ";
    while (true) {
        cin >> testCases;
        if (testCases >= 1 && testCases <= 10) break;
        cout << "Loi. So bo test tu 1 den 10. Nhap lai: ";
    }

    while (testCases--) {
        int n, d;
        cout << "Nhap so luong phan tu cua mang: ";
        while (true) {
            cin >> n;
            if (n >= 1 && n <= 1000000) break;
            cout << "Loi. So phan tu tu 1 den 10^6. Nhap lai: ";
        }

        cout << "Nhap so phep quay vong: ";
        while (true) {
            cin >> d;
            if (d >= 0 && d <= n) break;
            cout << "Loi. So quay vong tu 0 den n. Nhap lai: ";
        }

        vector<int> array(n);
        for (int i = 0; i < n; ++i) {
            while (true) {
                cin >> array[i];
                if (array[i] >= 1 && array[i] <= 100000) break;
                cout << "Loi. Gia tri tu 1 den 10^5. Nhap lai: ";
            }
        }

        rotateLeft(array, d);

        for (int num : array) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
