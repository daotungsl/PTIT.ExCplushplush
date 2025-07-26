#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    cout << "Nhap so phan tu cua day: ";
    while (true) {
        cin >> n;
        if (n >= 1 && n <= 100) break;
        cout << "Loi. So phan tu tu 1 den 100. Nhap lai: ";
    }

    set<int> uniqueNumbers;
    for (int i = 0; i < n; ++i) {
        int value;
        cout << "Nhap phan tu thu " << i + 1 << ": ";
        while (true) {
            cin >> value;
            if (value >= 1 && value <= 1000) break;
            cout << "Gia tri tu 1 den 1000. Nhap lai: ";
        }
        uniqueNumbers.insert(value);
    }

    cout << "Cac so khac nhau theo thu tu tang dan: ";
    for (int num : uniqueNumbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
