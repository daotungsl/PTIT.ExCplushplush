#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

struct SinhVien {
	string maSV;
	string hoTen;
	string lop;
	string email;
	
	bool nhap(const map<string, SinhVien>& danhSachSV);
	void xuat() const;
};

bool khongCoKhoangTrong(string s) {
	return s.find(' ') == string::npos;
}

bool SinhVien::nhap(const map<string, SinhVien>& danhSachSV) {
	//ma sinh vien
	cout << "Nhap ma sinh vien: ";
	while(true) {
		getline(cin, maSV);
		if(maSV == "STOP") return false;
		if(danhSachSV.count(maSV)) {
			cout << "Ma sinh vien " << maSV << " da ton tai. Nhap lai: ";
			continue;
		}
		if(maSV.length() <= 15 && khongCoKhoangTrong(maSV)) break;
		cout << "Loi: Ma sinh vien khong qua 15 ky tu va khong chua khoang trang. Nhap lai: ";
	}
	
	//ho ten
	cout << "Nhap ho ten: ";
	while(true) {
		getline(cin, hoTen);
		if(hoTen.length() <= 100) break;
		cout << "Loi: Ho ten khong qua 100 chu cai. Nhap lai: \n";	
	}

	//lop
	cout << "Nhap lop: ";
	while(true) {
		getline(cin, lop);
		if(lop.length() <= 15 && khongCoKhoangTrong(lop)) break;
		cout << "Loi: Lop khong qua 15 ky tu va khong chua khoang trang. Nhap lai: ";
	}
	
	//email
	cout << "Nhap email: ";
	while(true) {
		getline(cin, email);
		if(email.length() <= 15 && khongCoKhoangTrong(email)) break;
		cout << "Loi: Email khong qua 15 ky tu va khong chua khoang trang. Nhap lai: ";
	}
	return true;
}

void SinhVien::xuat() const {
	cout << maSV << " " << hoTen << " " << lop << " " << email << endl;
}

int main() {
	map<string, SinhVien> danhSachSV;
	int soLuong = 0;

	cout << "Nhap danh sach sinh vien (toi da 1000, nhap STOP o ma sinh vien de ket thuc):\n";

	while (true) {
		//Kiem tra so luong sinh vien
		if (soLuong >= 1000) {
			cout << "Da dat toi da 1000 sinh vien. Ket thuc nhap.\n";
			break;
		}
		
		//Nhap thong tin hoac ngat lenh nhap thong tin bang STOP
		SinhVien sv;
		if(!sv.nhap(danhSachSV)) break;
		
		//gan key va value
		danhSachSV[sv.maSV] = sv;
		soLuong++;
	}

	cout << "\nDanh sach sinh vien sau khi sap xep theo ma:\n";
	
	//Cu phap phu hop voi c++ 98
	for (map<string, SinhVien>::iterator it = danhSachSV.begin(); it != danhSachSV.end(); ++it) {
	    it->second.xuat(); 
	}

	return 0;
}

