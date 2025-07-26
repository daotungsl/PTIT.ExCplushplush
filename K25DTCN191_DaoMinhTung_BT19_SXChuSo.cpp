#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int t;
    cout << "Nhap so luong bo test: ";
    while (true) {
        cin >> t;
        if (t >= 1 && t <= 100) break;
        cout << "Loi: so test tu 1 den 100. Nhap lai: ";
    }

    while (t--) {
        int n;
        cout << "Nhap so phan tu trong mang: ";
        while (true) {
            cin >> n;
            if (n >= 1 && n <= 10000000) break;
            cout << "Loi: 1 <= n <= 10^7. Nhap lai: ";
        }

        vector<long long> arr(n);
        for (int i = 0; i < n; ++i) {
            while (true) {
                cin >> arr[i];
                if (arr[i] >= 0 && arr[i] <= 10000000000000000LL) break;
                cout << "Loi: 0 <= a[i] <= 10^16. Nhap lai: ";
            }
        }

        set<int> digits;
        for (long long num : arr) {
            while (num > 0) {
                int digit = num % 10;
                digits.insert(digit);
                num /= 10;
            }
        }

        for (int d : digits) {
            cout << d << " ";
        }
        cout << endl;
    }

    return 0;
}
