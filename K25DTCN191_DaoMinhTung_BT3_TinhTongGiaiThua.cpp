#include <iostream>
#include <cmath>
using namespace std;

void sum(int n) {
	long long a = 1, totalSum = 0;
	for(int i = 1; i <= n; i++) {
		a*= i;
		totalSum += a;
	};
	cout << "Ket qua la: " << totalSum; 
}
int main() {
	int n;
	while(true) {
		cout << "Nhap so n: ";
		cin >> n;
		if(n <= 20) break;
		cout << "Loi: n khong qua 20. Nhap lai: ";
	}
	
	sum(n);
	return 0;
}
