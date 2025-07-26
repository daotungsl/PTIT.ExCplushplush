#include <iostream>
#include <cmath>
using namespace std;

/* dùng bien temp, tranh dung i vi thay doi i trong while se lam for k
hoat dong dung do gia tri cua i thay doi. Va phai gan gia tri ban dau cho cac bien dem neu k chung se co gia tri rac*/

void checkEvenOddBalance(int n) { 
	int count = 0;
	for(int i = (int)pow(10, n - 1); i <= (int)(pow(10, n) - 1); i++) {
		int even = 0, odd = 0;
		int temp = i;
		while(temp > 0) {
			int m = temp % 10;
			if(m % 2 == 0) {
				even++;
			} else {
				odd++;
			};
			temp /= 10;
		};
		
		if(even == odd) {
			cout << i;
			count++;
			if(count % 10 == 0 && count != 0) {
				cout << endl;
			} else {
				cout << " ";
			}
		};
	};
	
};

int main() {
	int n;
	cout << "Nhap so n: ";
	while(true) {
		cin >> n;
		if(n > 1 && n < 7) break;
		cout << "Loi: 1 < n < 7. Nhap lai: ";
	}

	if(n % 2 == 0) {
		checkEvenOddBalance(n);
	}; 
	return 0;
};
