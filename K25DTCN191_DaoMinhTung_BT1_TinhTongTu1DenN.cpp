#include <iostream>
#include <cmath>
using namespace std;

void sum(long long N) {
	cout << N*(N + 1) / 2 << endl;
}
int main() {
	int t;
	cout << "Nhap so bo test: ";
	while(true) {
		cin >> t;
		if(t <= 10) break;
		cout << "Loi: So bo test khong qua 10. Nhap lai: ";
	}

	while(t--) {
		long long n;
		cout << "Nhap so nguyen duong n: ";
		while(true) {
			cin >> n;
			if(n > 0 && n <= 1000000000) break;
			cout << "Loi: So bo test khong qua 10. Nhap lai: ";
		}
		sum(n);
	}
	return 0;
}

