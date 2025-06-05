
#include <iostream>
using namespace std;

int main() {
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
    return 0;
}
