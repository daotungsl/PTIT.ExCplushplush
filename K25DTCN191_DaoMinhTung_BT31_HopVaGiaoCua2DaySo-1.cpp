#include <iostream>
using namespace std;

void sort(int *c, int length) {
	for(int i = 0; i < length; i++) {
		for(int j = i + 1; j < length; j++) {
			if(c[i] > c[j]) {
				int temp = c[j];
				c[j] = c[i];
				c[i] = temp;
			}
		}
	}
}

void uniqueNumber(int *c, int length) {
	int s = 0;
	int *d = new int[length];
	for(int i = 0; i < length; i++) {
		int f = 1;
		for(int j = i - 1; j >= 0; j--) {
			if(c[i] == c[j]) {
				f = 0;
				break;
			}
		}
		if(f) {
			s++;
			d[s - 1] = c[i];
		}
	}
	sort(d, s);
	for(int i = 0; i < s; i++) {
		cout << d[i] << " ";
	}
	cout << endl;
	delete[] d;
}

void unionArrays(int *a, int *b, int n, int m) {
	int length = n + m;
	int *c = new int[length];
	int count = 0;
	for(int i = 0; i < n; i++) {
		c[i] = a[i];
	}
	
	for(int i = 0; i < m; i++) {
		c[n + i] = b[i];
	}
	
	uniqueNumber(c, length);
	delete[] c;
}

void pushNumberToArray(int *c, int count, int i) {
	c[count - 1] = i;
}

void intersectArrays(int *a, int *b, int n, int m) {
	int length = n + m;
	int count = 0;
	int *c = new int[length];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(a[i] == b[j]) {
				count++;
				pushNumberToArray(c, count, a[i]);
			}
		}
	}
	
	sort(c, count);
	for(int i = 0; i < count; i++) {
		cout << c[i] << " ";
	}
	cout << endl;
	delete[] c;
}
int main() {
	int t;
	cout << "Nhap t: ";
	do {
		cin >> t;
	} while(t < 1 || t > 100);
	
	while(t--) {
		int n, m;
		do {
			cout << "Nhap n: ";
			cin >> n;
			cout << "Nhap m: ";
			cin >> m;
		} while(n < 1 || m < 1);
		
		int *a = new int[n];
		int *b = new int[m];
		for(int i = 0; i < n; i++) {
			do {
				cin >> a[i];	
			} while(a[i] > 100000);
		}
		
		
		for(int i = 0; i < m; i++) {
			do {
				cin >> b[i];	
			} while(b[i] > 100000);
		}
		
		unionArrays(a, b, n, m);
		intersectArrays(a, b, n, m);
		delete[] a;
		delete[] b;
	}
	return 0;
}
