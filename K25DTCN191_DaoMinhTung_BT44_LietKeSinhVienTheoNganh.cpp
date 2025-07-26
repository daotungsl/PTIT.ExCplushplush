#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <map>
#include <cctype>
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
		if(email.length() <= 50 && khongCoKhoangTrong(email)) break;
		cout << "Loi: Email khong qua 50 ky tu. Nhap lai: ";
	}
}

string locMaNganh(const string &maSV) {
	return maSV.substr(3, 4);
}

bool loaiTruNganh(const string& maSV, const string& maNganh) {
	if((maNganh == "DCAT" || maNganh == "DCCN") && maSV[0] == 'E') return false;
	return true;
}

void chuyenSangChuHoa(string& s) {
	for(int i = 0; i < s.length(); i++) {
		s[i] = toupper(s[i]);
	}
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
	cout << endl;
	
	vector <SinhVien> a(n);
	for(int i = 0; i < n; i++) {
		cout << "Nhap thong tin sinh vien so " << i + 1 << ": " << endl;
		a[i].nhap();
		cout << endl;
	}
	
	cout << "Nhap so luong nganh hoc can truy van: ";
	int q;
	while(true) {
		cin >> q;
		cin.ignore();
		if(q > 0 && q <= 5) break;
		cout << "Loi: So luong truy van khong qua 5 nganh hoc. Nhap lai: ";
	}
	cout << endl;
	
	map<string, string> maNganh;
	maNganh["KE TOAN"] = "DCKT";
	maNganh["CONG NGHE THONG TIN"] = "DCCN";
	maNganh["AN TOAN THONG TIN"] = "DCAT";
	maNganh["VIEN THONG"] = "DCVT";	
	maNganh["DIEN TU"] = "DCDT";
	
	map<int, string> tenNganh;
	for(int i = 0; i < q; i++) {
		cout << "Nhap ten nganh hoc so " << i + 1 << ": ";
		string s;
		getline(cin, s);
		chuyenSangChuHoa(s);
		tenNganh[i] = s;
	}
	cout << endl;
	
	for(int i = 0; i < q; i++) {
		int d = 0;
		string tenNganhHoc = tenNganh[i];
		string tenMaNganhHoc = maNganh[tenNganhHoc];
		
		cout << "DANH SACH SINH VIEN NGANH " << tenNganhHoc << ":" << endl;
		for(int j = 0; j < n; j++) {
			string maSV = a[j].maSV;
			string maNganhDuocLoc = locMaNganh(maSV);
			if(maNganhDuocLoc == tenMaNganhHoc && loaiTruNganh(maSV, maNganhDuocLoc)) {
				a[j].xuat();
				d++;
			}
		}
		if(!d) cout << "Khong co sinh vien nao thoa man truy van";
		cout << endl;
	}
	return 0;
}
