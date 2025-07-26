#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

struct SinhVien {
	string maSV;
	string hoTen;
	string lop;
	float diem1;
	float diem2;
	float diem3;
	
	void nhap();
	void xuat();
};

bool khongCoKhoangTrong(string s) {
	return s.find(' ') == string::npos;
}

void SinhVien::nhap() {
	//ma sinh vien
	cout << "Nhap ma sinh vien: ";
	while(true) {
		getline(cin, maSV);
		if(maSV.length() <= 15 && khongCoKhoangTrong(maSV)) break;
		cout << "Loi: Ma sinh vien khong qua 15 ky tu. Nhap lai: ";
	}
	
	//ho ten
	cout << "Nhap ho ten: ";
	while(true) {
		getline(cin, hoTen);
		if(hoTen.length() <= 30) break;
		cout << "Loi: Ho ten khong qua 30 chu cai. Nhap lai: ";	
	}

	//lop
	cout << "Nhap lop: ";
	while(true) {
		getline(cin, lop);
		if(lop.length() <= 15 && khongCoKhoangTrong(lop)) break;
		cout << "Loi: Lop khong qua 15 ky tu. Nhap lai: ";
	}
	
	//diem1
	cout << "Nhap diem 1: ";
	while(true) {
		cin >> diem1;
		if(diem1 >= 0.0 && diem1 <= 10.0) break;
		cout << "Loi: 0.0 <= diem1 <= 10.0. Nhap lai: ";
	}
	
	//diem2
	cout << "Nhap diem 2: ";
	while(true) {
		cin >> diem2;
		if(diem2 >= 0.0 && diem2 <= 10.0) break;
		cout << "Loi: 0.0 <= diem2 <= 10.0. Nhap lai: ";
	}
	
	//diem3
	cout << "Nhap diem 3: ";
	while(true) {
		cin >> diem3;
		cin.ignore();
		if(diem3 >= 0.0 && diem3 <= 10.0) break;
		cout << "Loi: 0.0 <= diem3 <= 10.0. Nhap lai: ";
	}
}

bool cmp(SinhVien a, SinhVien b) {
	return a.maSV < b.maSV;
}

void SinhVien::xuat() {
	cout << maSV << " " << hoTen << " " << lop << " " << fixed << setprecision(1) << diem1 << " " << diem2 << " " << diem3 << endl;
}

int main() {
	int n;
	cout << "Nhap so luong sinh vien: ";
	while(true) {
		cin >> n;
		cin.ignore();
		if(0 < n && n <= 100) break;
		cout << "Loi: So luong sinh vien khong qua 100. Nhap lai: ";
	}
	
	vector <SinhVien> a(n);
	
	for(int i = 0; i < n; i++) {
		a[i].nhap();
	}
	
	sort(a.begin(), a.end(), cmp);
	
	for(int i = 0; i < n; i++) {
		cout << i + 1 << " ";
		a[i].xuat();
	}
	return 0;
}
