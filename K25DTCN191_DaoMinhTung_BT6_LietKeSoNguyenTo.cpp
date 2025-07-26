#include <iostream>
#include <cmath>
using namespace std;


void checkPrime(int a, int b) {
	for(int j = a; j <= b; j++) {
		int f = 1;
	
		for(int i = 2; i <= sqrt(j); i++) {
			if(j % i == 0) {
				f = 0;
				break;
			};
		};
	
		if(f && j >= 2) {
			cout << j << " ";
		};
	};
}
int main() {
	int a, b;
	cout << "Nhap so nguyen duong a: ";
	while(true) {
		cin >> a;
		if(a > 0 && a <= 1000000) break;
		cout << "Loi. a la so nguyen duong khong qua 10^6. Nhap lai: ";
	}
	
	cout << "Nhap so nguyen duong b: ";
	while(true) {
		cin >> b;
		if(b > 0 && b <= 1000000) break;
		cout << "Loi. b la so nguyen duong khong qua 10^6. Nhap lai: ";
	}
	
	checkPrime(a, b);
	return 0;
}
