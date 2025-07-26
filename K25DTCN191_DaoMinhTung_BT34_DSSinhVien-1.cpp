#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cctype>

using namespace std;

struct SinhVien {
    string maSV;
    string hoTen;
    string lop;
    string ngaySinh;
    float gpa;

    static int dem;

    void nhap() {
     	cout << "Nhap ten: ";
        while (true) {
            getline(cin, hoTen);
            if (hoTen.length() <= 30) break;
            cout << "Loi: Ho ten khong duoc vuot qua 30 ky tu. Nhap lai: ";
        }
	
		cout << "Nhap lop: ";
        getline(cin, lop);

 		cout << "Nhap ngay sinh: ";
        while (true) {
            getline(cin, ngaySinh);
            if (chuanHoaNgaySinh()) break;
            cout << "Loi: Ngay sinh khong hop le. Nhap lai: ";
        }
		
		cout << "Nhap Gpa: ";
        while (true) {
            string gpaStr;
            getline(cin, gpaStr);
            stringstream ss(gpaStr);
            if ((ss >> gpa) && gpa >= 0.0 && gpa <= 4.0) break;
            cout << "Loi: GPA khong hop le (0.0 - 4.0). Nhap lai: ";
        }

 		dem++;
       	stringstream ss;
       	ss << dem;
       	maSV = "B20DCCN";
       	if(dem < 10) maSV += "00";
       	else maSV += "0";
       	maSV += ss.str();

    }

    void xuat() {
        cout << maSV << " " << hoTen << " " << lop << " " << ngaySinh << " " << fixed << setprecision(2) << gpa << endl;
    }

    bool chuanHoaNgaySinh() {
        stringstream ss(ngaySinh);
        string d, m, y;
        getline(ss, d, '/');
        getline(ss, m, '/');
        getline(ss, y);

        if (d.empty() || m.empty() || y.empty()) return false;
        if (d.length() == 1) d = "0" + d;
        if (m.length() == 1) m = "0" + m;

        if (!laNgayHopLe(d, m, y)) return false;

        ngaySinh = d + "/" + m + "/" + y;
        return true;
    }

    bool laNgayHopLe(string d, string m, string y) {
        int dd, mm, yyyy;
        stringstream(d) >> dd;
        stringstream(m) >> mm;
        stringstream(y) >> yyyy;

        if (yyyy < 1900 || yyyy > 2025) return false;
        if (mm < 1 || mm > 12) return false;
        if (dd < 1) return false;

        int ngayThang[] = {31, 28, 31, 30, 31, 30,
                           31, 31, 30, 31, 30, 31};

        if (namNhuan(yyyy)) ngayThang[1] = 29;

        if (dd > ngayThang[mm - 1]) return false;
        return true;
    }

    bool namNhuan(int y) {
        return (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0));
    }
};

int SinhVien::dem = 0;

int main() {
    int N;
    while (true) {
        cin >> N;
        cin.ignore();
        if (N > 0 && N < 50) break;
        cout << "Loi: So luong sinh vien khong hop le (1 - 49). Nhap lai: ";
    }

    SinhVien sv[50];
    for (int i = 0; i < N; ++i) {
        cout << "Nhap thong tin sinh vien thu " << i + 1 << ":\n";
        sv[i].nhap();
    }

    for (int i = 0; i < N; ++i) {
        sv[i].xuat();
    }

    return 0;
}

