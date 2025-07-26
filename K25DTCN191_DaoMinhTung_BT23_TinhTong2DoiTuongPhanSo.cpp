#include <iostream>
#include <algorithm> 
using namespace std;

class PhanSo {
	private: 
	long long tu, mau;	
	public:
	    PhanSo(long long tu = 0, long long mau = 1){
	        this->tu = tu;
	        this->mau = mau;
	        rutGon();
	    }
	
	    void rutGon() {
	        long long gcd = __gcd(tu, mau);
	        tu /= gcd;
	        mau /= gcd;
	    }
	
	    PhanSo operator+(PhanSo &khac) {
	    	long long tuMoi = tu * khac.mau + khac.tu * mau;
	    	long long mauMoi = mau * khac.mau;
	    	return PhanSo(tuMoi, mauMoi);
		}
	
	    void in() {
	        cout << tu << "/" << mau << endl;
	    }
};

int main() {
    long long tu1, mau1, tu2, mau2;
    cin >> tu1 >> mau1 >> tu2 >> mau2;
    PhanSo p(tu1, mau1);
    PhanSo q(tu2, mau2);
    PhanSo tong = p + q;
    tong.in();
    return 0;
}

