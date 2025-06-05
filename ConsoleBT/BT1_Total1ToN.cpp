//#include "BT1_Total1ToN.h"
#include <iostream>
using namespace std;

void BT1_Total1ToN() {
    int T;
    cout << "Nhap so test: ";
    cin >> T;
    while (T--) {
        long long N;
        cin >> N;
        long long sum = 0;
        for (int i = 1; i <= N; ++i) {
            sum += i;
        }
        cout << "Tong tu 1 den " << N << " la: " << sum << endl;
    }
}
