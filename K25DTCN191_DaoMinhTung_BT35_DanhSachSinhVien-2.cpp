#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

struct SinhVien {
	string maSV;
	string hoTen;
	string lop;
	string ngaySinh;
	float gpa;
	
	static int dem;	
	
	bool chuanHoaNgaySinh();
	bool kiemTraNgaySinh(string d, string m, string y);
	void nhap();
	void xuat();
};

int SinhVien::dem = 0;

bool SinhVien::kiemTraNgaySinh(string d, string m, string y) {
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
	 		if(((yyyy % 400 == 0) || (yyyy % 100 != 0 && yyyy % 4 == 0)) ? dd != 29 : dd !=28) return false;
	 		break;
	 	default:
	 		return false;
	}
	return true;
}

bool SinhVien::chuanHoaNgaySinh() {
	stringstream ss(ngaySinh);
	string d, m, y;
	getline(ss, d, '/');
	getline(ss, m, '/');
	getline(ss, y, '/');
	
	if(d.empty() || m.empty() || y.empty()) return false;
	if(d.length() == 1) d = "0" + d;
	if(m.length() == 1) m = "0" + m;
	if(!kiemTraNgaySinh(d, m, y)) return false;
	
	ngaySinh = d + '/' + m + '/' + y;
	return true;
}

void SinhVien::nhap() {
	//ma sinh vien
	maSV = "B20DCCN";
	dem++;
	stringstream ss;
	ss << dem;
	if(dem < 10) {
		maSV += "00";
	} else if(dem >=10 && dem <= 99){
		maSV += "0";
	}
	maSV += ss.str();
	
	//ho ten
	cout << "Nhap ho ten: ";
	while(true) {
		getline(cin, hoTen);
		if(hoTen.length() <= 30) break;
		cout << "Loi: Ho ten khong qua 30 chu cai. Nhap lai: ";	
	}
	cout << endl;
	//lop
	cout << "Nhap lop: ";
	getline(cin, lop);
	cout << endl;
	//ngay sinh
	cout << "Nhap ngay sinh: ";
	while(true) {
		getline(cin, ngaySinh);
		if(chuanHoaNgaySinh()) break;
		cout << "Loi: Ngay sinh khong dung. Nhap lai: ";
	}
	cout << endl;
	//gpa
	cout << "Nhap gpa: ";
	while(true) {
		cin >> gpa;
		if(gpa >= 2.00 && gpa <= 4.00) break;
		cout << "Loi: 2.00 <= gpa <= 4.00. Nhap lai: ";
	}
}

void SinhVien::xuat() {
	cout << maSV << " " << hoTen << " " << lop << " " << ngaySinh << " " << fixed << setprecision(2) << gpa << endl;
}

int main() {
	int n;
	cout << "Nhap so bo test: ";
	while(true) {
		cin >> n;
		if(0 < n && n < 50) break;
		cout << "Loi: 0 < n < 50. Nhap lai: ";
	}
	
	while(n--) {
		cin.ignore();
		SinhVien a;
		cout << "Nhap thong tin sinh vien so " << a.dem + 1 << ": " << endl;
		a.nhap();
		cout << endl;
		a.xuat();
		cout << endl;
	}
	return 0;
}
