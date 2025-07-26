#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Nhap so luong phan tu: ";
    while (true) {
        cin >> n;
        if (n >= 1 && n <= 10000) break;
        cout << "Loi: 1 <= n <= 10000. Nhap lai: ";
    }

    vector<int> a(n);
    cout << "Nhap cac phan tu: ";
    for (int& x : a) {
        cin >> x;
    }

    sort(a.begin(), a.end()); // tăng dần

    vector<int> kq(n);
    int l = 0, r = n - 1;

    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0)
            kq[i] = a[r--]; // chẵn → max
        else
            kq[i] = a[l++]; // lẻ → min
    }

    cout << "Day sau khi sap xep xen ke: ";
    for (int x : kq) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
