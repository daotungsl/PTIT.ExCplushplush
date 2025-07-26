#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

struct NhanVien {
	string maNV;
	string hoTen;
	string gioiTinh;
	string ngaySinh;
	string diaChi;
	string maSoThue;
	string ngayKyHopDong;
	
	static int dem;
	bool kiemTraNgay(string d, string m, string y);
	bool chuanHoaNgay(string &ngay);
	friend istream& operator >> (istream &nhap, NhanVien& a);
	friend ostream& operator << (ostream &xuat, NhanVien a);
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

istream& operator >> (istream &nhap, NhanVien& a){
	//ma NV
	a.maNV = "";
	a.dem++;
	stringstream ss;
	ss << setw(5) << setfill('0') << a.dem;
	a.maNV += ss.str();
	
	//ten
	cout << "Nhap ho ten: ";
	while(true) {
		getline(nhap, a.hoTen);
		if(a.hoTen.length() <= 40) break;
		cout << "Loi: Ho ten khong qua 40 chu cai. Nhap lai: ";
	}
	
	//gioi tinh
	cout << "Nhap gioi tinh: ";
	while(true) {
		getline(nhap, a.gioiTinh);
		if(a.gioiTinh == "Nam" || a.gioiTinh == "Nu") break;
		cout << "Loi: Gioi tinh khong dung. Nhap lai: ";
	}
	
	//ngay sinh
	cout << "Nhap ngay sinh: ";
	while(true) {
		getline(nhap, a.ngaySinh);
		if(a.chuanHoaNgay(a.ngaySinh)) break;
		cout << "Loi: Ngay sinh khong dung. Nhap lai: ";
	}
	
	//dia chi
	cout << "Nhap dia chi: ";
	while(true) {
		getline(nhap, a.diaChi);
		if(a.diaChi.length() <= 100) break;
		cout << "Loi: Ho ten khong qua 100 chu cai. Nhap lai: ";
	}
	
	//ma so thue
	cout << "Nhap ma so thue: ";
	while(true) {
		getline(nhap, a.maSoThue);
		if(a.maSoThue.length() == 10 && a.maSoThue.find_first_not_of("0123456789") == string::npos) break;
		cout << "Loi: Ma so thue khong dung dinh dang. Nhap lai: ";
	}
	
	//Ngay ky hop dong
	cout << "Ngay ky hop dong: ";
	while(true) {
		getline(nhap, a.ngayKyHopDong);
		if(a.chuanHoaNgay(a.ngayKyHopDong)) break;
		cout << "Loi: Ngay ky hop dong khong dung dinh dang. Nhap lai: ";
	}
	
	return nhap;
}

ostream& operator << (ostream &xuat, NhanVien a) {
	xuat << a.maNV << " " << a.hoTen << " " << a.gioiTinh << " " << a.ngaySinh << " " << a.diaChi << " " << a.maSoThue << " " << a.ngayKyHopDong << " " << endl;
	return xuat;
}

int NhanVien::dem = 0;

int main() {
	int n;
	cout << "Nhap so luong nhan vien: ";
	while(true) {
		cin >> n;
		cin.ignore();
		if(n > 0 && n <= 40) break;
		cout << "Loi: So luong nhan vien khong qua 40: ";
	}
	
	vector <NhanVien> a(n);
	for(int i = 0; i < n; i++) {
		cout << "Nhap thong tin nhan vien so " << i + 1 << endl;
		cin >> a[i];
	}
	
	for(int i = 0; i < n; i++) {
		cout << a[i];
	}
	
	return 0;
}
