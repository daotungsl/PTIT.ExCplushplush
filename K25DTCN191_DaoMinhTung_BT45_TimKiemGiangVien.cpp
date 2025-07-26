#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <cctype>
using namespace std;

struct GiangVien {
	string maGV;
	string hoTen;
	string boMon;
	
	static int dem;
	void nhap();
	void xuat();
};

int GiangVien::dem = 0;

void chuyenSangChuHoa(string& s) {
	for(int i = 0; i < s.length(); i++) {
		s[i] = toupper(s[i]);
	}
}

void vietTatBoMon(string& s) {
	stringstream ss(s);
	string tu, vietTat;
	while(ss >> tu) {
		vietTat += tu[0];
	}
	chuyenSangChuHoa(vietTat);
	s = vietTat;
}

void GiangVien::nhap() {
	//ma giang vien
	dem++;
	stringstream ss;
	ss << dem;
	maGV = "GV";
	if(dem < 10) maGV += "0";
	maGV += ss.str();
	
	//ho ten
	cout << "Nhap ho ten: ";
	while(true) {
		getline(cin, hoTen);
		if(hoTen.length() <= 50) break;
		cout << "Loi: Ho ten khong qua 50 chu cai. Nhap lai: ";	
	}

	//bo mon
	cout << "Nhap bo mon: ";
	while(true) {
		getline(cin, boMon);
		if(boMon.length() <= 30) {
			vietTatBoMon(boMon);
			break;
		}
		cout << "Loi: Bo mon khong qua 30 ky tu. Nhap lai: ";
	}
	
}

void GiangVien::xuat() {
	cout << maGV << " " << hoTen << " " << boMon << endl;
}

int main() {
	int n;
	cout << "Nhap so luong giang vien: ";
	cin >> n;
	cin.ignore();
	cout << endl;
	
	vector <GiangVien> a(n);
	for(int i = 0; i < n; i++) {
		cout << "Nhap thong tin giang vien so " << i + 1 << ": " << endl;
		a[i].nhap();
		cout << endl;
	}
	
	cout << "Nhap so luong tu khoa can truy van: ";
	int q;
	cin >> q;
	cin.ignore();
	cout << endl;
	
	map<int, string> tuKhoa;
	for(int i = 0; i < q; i++) {
		cout << "Nhap tu khoa so " << i + 1 << ": ";
		string s;
		getline(cin, s);
		tuKhoa[i] = s;
	}
	cout << endl;
	
	for(int i = 0; i < q; i++) {
		int d = 0;
		string tuKhoaCanTim = tuKhoa[i];
		
		cout << "DANH SACH GIANG VIEN THEO TU KHOA " << tuKhoaCanTim << ":" << endl;
		chuyenSangChuHoa(tuKhoaCanTim);
		for(int j = 0; j < n; j++) {
			string tenGiangVien = a[j].hoTen;
			chuyenSangChuHoa(tenGiangVien);
			
			if(tenGiangVien.find(tuKhoaCanTim) != string::npos) {
				a[j].xuat();
				d++;
			}
		}
		if(!d) cout << "Khong co giang vien nao thoa man truy van";
		cout << endl;
	}
	return 0;
}
