#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

struct NhanVien {
	string hoTen;
	string ngaySinh;
	
	bool kiemTraNgay(string d, string m, string y);
	bool chuanHoaNgay(string &ngay);
	void nhap();
	void xuat();
};

bool NhanVien::kiemTraNgay(string d, string m, string y) {
	int dd, mm, yyyy;
	stringstream(d) >> dd;
	stringstream(m) >> mm;
	stringstream(y) >> yyyy;
	
	if(dd <= 0 || mm <= 0 || yyyy <= 0) return false;
	switch(mm) {
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			if(dd > 31) return false;
			break;
		case 4: case 6: case 9: case 11:
			if(dd > 30) return false;
			break;
		case 2:
			if(((yyyy % 400 == 0) || (yyyy % 100 != 0 && yyyy % 4 == 0)) ? dd > 29 : dd > 28) return false;
			break;
		default:
			return false;	
	}
	return true;
}

bool NhanVien::chuanHoaNgay(string &ngay) {
	stringstream ss(ngay);
	string d, m, y;
	getline(ss, d, '/');
	getline(ss, m, '/');
	getline(ss, y, '/');
	
	if(d.empty() || m.empty() || y.empty()) return false;
	if(d.length() == 1) d = "0" + d;
	if(m.length() == 1) m = "0" + m;
	
	if(!kiemTraNgay(d, m, y)) return false;
	ngay = d + '/' + m + '/' + y;
	return true;
}

void NhanVien::nhap() {
	//ten
	cout << "Nhap ho ten: ";
	while(true) {
		getline(cin, hoTen);
		if(hoTen.length() <= 15) break;
		cout << "Loi: Ho ten khong qua 15 chu cai. Nhap lai: ";
	}
	
	//ngay sinh
	cout << "Nhap ngay sinh: ";
	while(true) {
		getline(cin, ngaySinh);
		if(chuanHoaNgay(ngaySinh)) break;
		cout << "Loi: Ngay sinh khong dung. Nhap lai: ";
	}
}

void NhanVien::xuat() {
	cout << hoTen << endl;
}


int chuyenDoiNgaySinh(string s) {
	int d, m, y;
	char ch;
	stringstream ss(s);
	ss >> d >> ch >> m >> ch >> y;
	return y * 10000 + m * 100 + d; 
}

bool cmp(NhanVien a, NhanVien b) {
	return chuyenDoiNgaySinh(a.ngaySinh) > chuyenDoiNgaySinh(b.ngaySinh);
}

int main() {
	int n;
	cout << "Nhap so luong nhan vien: ";
	while(true) {
		cin >> n;
		cin.ignore();
		if(n > 0 && n <= 100) break;
		cout << "Loi: So luong nhan vien khong qua 100: ";
	}
	
	vector <NhanVien> a(n);
	for(int i = 0; i < n; i++) {
		cout << "Nhap thong tin nhan vien so " << i + 1 << endl;
		a[i].nhap();
	}
	
	sort(a.begin(), a.end(), cmp);
	
	for(int i = 0; i < n; i++) {
		if(i == 0 || i == n - 1) {
			a[i].xuat();
		}
	}
	
	return 0;
}
