#include <iostream>
#include <cmath>
using namespace std;

void elementWiseMultiply(int ** a, int **b, int n, int m) {
	int numBlocks = n / m;
	for(int p = 0; p < numBlocks; p++) {
		for(int q = 0; q < numBlocks; q++) {
			for(int i = 0; i < m; i++) {
				for(int j = 0; j < m; j++) {
					a[i + m * p][j + m * q] *= b[i][j];
				}
			}
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}


int main() {
	int n = 4;
	cout << "Nhap n: ";
	do {
		if(n <= 3 || n >= 100) {
			cout << "Nhap lai n: ";
		}
		cin >> n;
	} while(n <= 3 || n >= 100);
	
	int **a = new int*[n];
	for(int i = 0; i < n; i++) {
		a[i] = new int[n];
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			a[i][j] = 1;
			cout << "Nhap gia tri a" << "[" << i << "]" << "[" << j << "]: ";
			do {
				if(a[i][j] <= 0 || a[i][j] > 1000) {
					cout << "Nhap lai gia tri a[i][j]: ";
				}
				cin >> a[i][j];
			} while(a[i][j] <= 0 || a[i][j] > 1000);
			
		}
	}
	
	int m = 2;
	cout << "Nhap m: ";
	do {
		if((m <= 1 || m >= 10) || (n % m != 0)) {
			cout << "Nhap lai m: ";
		}
		cin >> m;
	} while((m <= 1 || m >= 10) || (n % m != 0));
	
	int **b = new int*[m];
	for(int i = 0; i < m; i++) {
		b[i] = new int[m];
	}
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < m; j++) {
			b[i][j] = 0;
			cout << "Nhap gia tri b" << "[" << i << "]" << "[" << j << "]: ";
			do {
				if(b[i][j] < 0 || b[i][j] > 20) {
					cout << "Nhap lai gia tri b[i][j]: ";
				}
				cin >> b[i][j];
			} while(b[i][j] < 0 || b[i][j] > 20);
		}
	}
	
	//Ham xu ly
	elementWiseMultiply(a, b, n, m);
	
	//Xoa bo nho dong
	for(int i = 0; i < n; i++) {
		delete[] a[i];
	}
	delete[] a;
	
	for(int i = 0; i < m; i++) {
		delete[] b[i];
	}
	delete[] b;
	return 0;
}
