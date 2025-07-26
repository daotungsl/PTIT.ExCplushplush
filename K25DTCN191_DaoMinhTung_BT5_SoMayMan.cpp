#include <iostream>
using namespace std;

void checkLuckyNumber(int n) {
	int temp = n % 100;
	if(temp == 86) {
		cout << 1;
	} else {
		cout << 0;
	}
}

int main() {
	int t;
	cout << "Nhap so luong bo test: ";
	while(true) {
		cin >> t;
		if(t > 0 && t <= 20) break;
		cout << "Loi: So luong bo test khong qua 20. Nhap lai: ";
	}

	while(t--) {
		int n;
		cout << "Nhap so nguyen n: ";
		while(true) {
			cin >> n;
			if(-999999999 <= n && n <= 999999999) break;
			cout << "Loi: So nguyen n khong qua 9 chu so. Nhap lai: ";
		}
		checkLuckyNumber(n);
		cout << endl;
	}
	return 0;
}
