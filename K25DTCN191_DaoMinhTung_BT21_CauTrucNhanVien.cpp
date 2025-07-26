#include <bits/stdc++.h>
using namespace std;

typedef struct {
	string maNhanVien = "00001";
	string ten;
	string gioiTinh;
	string ngaySinh;
	string diaChi;
	string maSoThue;
	string ngayKyHopDong; 
} NhanVien;

bool kiemTraDinhDangNgay(string ngayThangNam) {
	if(ngayThangNam.size() < 10) {
		return 0;
	}
	if(ngayThangNam[2] != '/'|| ngayThangNam[5] != '/') {
			return 0;
	}
	for(int i = 0; i < ngayThangNam.size(); i++) {
		if(i == 2 || i == 5) {
			continue;
		}
		if(ngayThangNam[i] < '0' || ngayThangNam[i] > '9') {
			return 0;
		}
	}
	
	int ngay = (ngayThangNam[0] - '0')* 10 + (ngayThangNam[1] - '0');
	int thang = (ngayThangNam[3] - '0')* 10 + (ngayThangNam[4] - '0');
	int nam = (ngayThangNam[6] - '0')* 1000 + (ngayThangNam[7] - '0') * 100 + (ngayThangNam[8] - '0') * 10 + (ngayThangNam[9] - '0');
	
	if(thang > 12 || thang < 0) {
		return 0;
	}
	switch(thang) {
		case 1: case 3: case 5: case 7: case 8: case 10: case 12: 
			if(ngay > 31) {
				return 0;
			};
			break;
		case 4: case 6: case 9: case 11:
			if(ngay > 30) {
				return 0;
			}
			break;
		case 2:
			if(((nam % 400 == 0) || (nam % 4 == 0 && nam % 100 != 0)) ? (ngay > 29) : (ngay > 28)) {
				return 0;
			}
	}
	return 1;
}

int main() {
	NhanVien a;
	do {
		getline(cin, a.ten);
	} while(a.ten.size() > 40);
	do {
		getline(cin, a.gioiTinh);
	} while(a.gioiTinh != "Nam" && a.gioiTinh != "Nu");
	do {
		getline(cin, a.ngaySinh);
	} while(!kiemTraDinhDangNgay(a.ngaySinh));
	do {
		getline(cin, a.diaChi);
	} while(a.diaChi.size() > 100);
	do {
		getline(cin, a.maSoThue);
	} while(a.maSoThue.size() > 10);
	do {
		getline(cin, a.ngayKyHopDong);
	} while(!kiemTraDinhDangNgay(a.ngayKyHopDong));
	
	cout << a.maNhanVien << " " << a.ten << " " << a.ngaySinh << " " << a.diaChi << " " << a.maSoThue << " " << a.ngayKyHopDong;
	return 0;
}

