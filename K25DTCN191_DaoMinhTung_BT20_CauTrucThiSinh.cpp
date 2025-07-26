#include <iostream>
#include <string>
using namespace std;

struct ThiSinh {
    string hoTen;
    string ngaySinh;
    float diemMon1;
    float diemMon2;
    float diemMon3;
};

bool isLeapYear(int year) {
    return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}

bool kiemTraNgaySinh(const string& ns) {
    if (ns.size() != 10 || ns[2] != '/' || ns[5] != '/') return false;

    int day = stoi(ns.substr(0, 2));
    int month = stoi(ns.substr(3, 2));
    int year = stoi(ns.substr(6, 4));

    if (day <= 0 || month <= 0 || year <= 0) return false;
    if (month > 12) return false;

    int maxDay = 31;
    if (month == 2) {
        maxDay = isLeapYear(year) ? 29 : 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        maxDay = 30;
    }

    if (day > maxDay) return false;
    return true;
}

float tinhTongDiem(const ThiSinh& ts) {
    return ts.diemMon1 + ts.diemMon2 + ts.diemMon3;
}

int main() {
    ThiSinh ts;
    cout << "Nhap ho ten: ";
    while (true) {
        getline(cin, ts.hoTen);
        if (ts.hoTen.length() <= 50) break;
        cout << "Ten qua dai. Nhap lai: ";
    }

    cout << "Nhap ngay sinh (dd/mm/yyyy): ";
    while (true) {
        getline(cin, ts.ngaySinh);
        if (kiemTraNgaySinh(ts.ngaySinh)) break;
        cout << "Ngay sinh khong hop le. Nhap lai (dd/mm/yyyy): ";
    }

    cout << "Nhap diem 3 mon: ";
    while (true) {
        cin >> ts.diemMon1 >> ts.diemMon2 >> ts.diemMon3;
        if (ts.diemMon1 >= 0 && ts.diemMon1 <= 10 &&
            ts.diemMon2 >= 0 && ts.diemMon2 <= 10 &&
            ts.diemMon3 >= 0 && ts.diemMon3 <= 10) break;
        cout << "Diem moi mon tu 0 den 10. Nhap lai: ";
    }

    float tongDiem = tinhTongDiem(ts);
    cout << ts.hoTen << " " << ts.ngaySinh << " " << tongDiem << endl;

    return 0;
}
