#include <iostream>
#include <vector>
using namespace std;

void bienDoiDay(vector<int>& a) {
    int n = a.size();
    int maxRight = -1;

    for (int i = n - 1; i >= 0; --i) {
        int temp = a[i];
        a[i] = maxRight;
        maxRight = max(maxRight, temp);
    }
}

int main() {
    int n;
    cout << "Nhap so luong phan tu: ";
    while (true) {
        cin >> n;
        if (n >= 1 && n <= 1000000) break;
        cout << "Loi: 1 <= n <= 1e6. Nhap lai: ";
    }

    vector<int> a(n);
    cout << "Nhap day so:\n";
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    bienDoiDay(a);

    cout << "Day sau bien doi:\n";
    for (int x : a) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
