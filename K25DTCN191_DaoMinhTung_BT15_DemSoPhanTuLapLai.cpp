#include <iostream>
#include <unordered_map>
using namespace std;

int countRepeatedElements(int arr[], int n) {
    unordered_map<int, int> freq;
    for (int i = 0; i < n; ++i) {
        freq[arr[i]]++;
    }

    int repeated = 0;
    for (auto& entry : freq) {
        if (entry.second > 1) {
            repeated++;
        }
    }

    return repeated;
}

int main() {
    int t;
    cout << "Nhap so bo test: ";
    while (true) {
        cin >> t;
        if (t >= 1 && t <= 100) break;
        cout << "Loi: so bo test tu 1 den 100. Nhap lai: ";
    }

    while (t--) {
        int n;
        cout << "Nhap so phan tu cua mang: ";
        while (true) {
            cin >> n;
            if (n >= 1 && n <= 1000000) break;
            cout << "Loi: n tu 1 den 10^6. Nhap lai: ";
        }

        int* arr = new int[n];
        for (int i = 0; i < n; ++i) {
            while (true) {
                cin >> arr[i];
                if (arr[i] >= 1 && arr[i] <= 1000000) break;
                cout << "Gia tri tu 1 den 10^6. Nhap lai: ";
            }
        }

        int result = countRepeatedElements(arr, n);
        cout << "So luong phan tu bi lap: " << result << endl;

        delete[] arr;
    }

    return 0;
}
