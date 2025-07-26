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
	string email;
	
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
		if(hoTen.length() <= 100) break;
		cout << "Loi: Ho ten khong qua 100 chu cai. Nhap lai: ";	
	}

	//lop
	cout << "Nhap lop: ";
	while(true) {
		getline(cin, lop);
		if(lop.length() <= 15 && khongCoKhoangTrong(lop)) break;
		cout << "Loi: Lop khong qua 15 ky tu. Nhap lai: ";
	}
	
	//email
	cout << "Nhap email: ";
	while(true) {
		getline(cin, email);
		if(email.length() <= 15 && khongCoKhoangTrong(email)) break;
		cout << "Loi: Email khong qua 15 ky tu. Nhap lai: ";
	}
}

bool cmp(SinhVien a, SinhVien b) {
	if(a.lop == b.lop) {
		return a.maSV < b.maSV;
	}
	return a.lop < b.lop;
}

void SinhVien::xuat() {
	cout << maSV << " " << hoTen << " " << lop << " " << email << endl;
}

int main() {
	int n;
	cout << "Nhap so luong sinh vien: ";
	while(true) {
		cin >> n;
		cin.ignore();
		if(0 < n && n <= 1000) break;
		cout << "Loi: So luong sinh vien khong qua 1000. Nhap lai: ";
	}
	
	vector <SinhVien> a(n);
	
	for(int i = 0; i < n; i++) {
		cout << "Nhap thong tin sinh vien so " << i + 1 << endl;
		a[i].nhap();
	}
	
	sort(a.begin(), a.end(), cmp);
	
	for(int i = 0; i < n; i++) {
		cout << i + 1 << " ";
		a[i].xuat();
	}
	return 0;
}
