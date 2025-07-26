#include <iostream>
#include <numeric>  // std::gcd
using namespace std;

class PhanSo {
private:
    int tu;
    int mau;

public:
    void nhap() {
        cout << "Nhap tu so: ";
        cin >> tu;
        cout << "Nhap mau so (khac 0): ";
        while (true) {
            cin >> mau;
            if (mau != 0) break;
            cout << "Mau so phai khac 0. Nhap lai: ";
        }
    }

    void rutGon() {
        int ucln = gcd(abs(tu), abs(mau));
        tu /= ucln;
        mau /= ucln;

        // Đưa dấu âm về tử
        if (mau < 0) {
            tu = -tu;
            mau = -mau;
        }
    }

    void xuat() {
        cout << "Phan so sau khi rut gon: " << tu << "/" << mau << endl;
    }
};

int main() {
    PhanSo ps;
    ps.nhap();
    ps.rutGon();
    ps.xuat();
    return 0;
}
