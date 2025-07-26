#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct DoanhNghiep {
	string maDN;
	string tenDN;
	int soSV;
	
	void nhap();
	void xuat();	
};

bool khongCoKhoangTrang(const string& s) {
	return s.find(' ') == string::npos;
}

void DoanhNghiep::nhap() {
	//ma DN
	cout << "Nhap ma doanh nghiep: ";
	while(true) {
		getline(cin, maDN);
		if(maDN.length() <= 10 && khongCoKhoangTrang(maDN)) break;
		cout << "Loi: Do dai ky tu khong qua 10 va khong co khoang trang. Nhap lai: ";	
	}
	
	//ten DN
	cout << "Nhap ten doanh nghiep: ";
	while(true) {
		getline(cin, tenDN);
		if(tenDN.length() <= 150) break;
		cout << "Loi: Do dai ky tu khong qua 150. Nhap lai: ";
	}
	
	//so sinh vien
	cout << "Nhap so luong sinh vien co the nhan: ";
	while(true) {
		cin >> soSV;
		cin.ignore();
		if(soSV <= 1000) break;
		cout << "Loi: So sinh vien khong qua 1000. Nhap lai: ";
	}
}

bool sapXepGiamDan(const DoanhNghiep& a, const DoanhNghiep& b) {
	return a.soSV > b.soSV;
}

void DoanhNghiep::xuat() {
	cout << maDN << " " << tenDN << " " << soSV << endl;
}

int main() {
	int dn;
	cout << "Nhap so luong doanh nghiep: ";
	cin >> dn;
	cin.ignore();
	cout << endl;
	
	vector<DoanhNghiep> a(dn);
	
	for(int i = 0; i < dn; i++) {
		cout << "Nhap thong tin doanh nghiep so" << i + 1 << ":" << endl;
		a[i].nhap();
		cout << endl;
	}
	
	sort(a.begin(), a.end(), sapXepGiamDan);
	
	for(int i = 0; i < dn; i++){
		a[i].xuat();
	}
	
	return 0;
}
