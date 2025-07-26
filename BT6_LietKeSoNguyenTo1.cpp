#include <iostream>
using namespace std;

int main(){
 int soNguyenDuongThuNhat = 0;
 int soNguyenDuongThuHai = 0;

    while(true){
      cout << "nhap so nguyen duong thu nhat: " << endl;
      cin >> soNguyenDuongThuNhat
      if(soNguyenDuongThuNhat < 0){
        cout << "khong phai so nguyen duong vui long nhap lai: " << endl;
      }else if(soNguyenDuongThuNhat > 10000000){
        cout << "so nhap vao lon hon 10 mu 6 vui long nhap lai: " << endl;
      }else{
          break;
      }
	}

    while(true){
      cout << "nhap so nguyen duong thu hai: " << endl;
      cin >> soNguyenDuongThuHai
      if(soNguyenDuongThuHai < 0){
        cout << "khong phai so nguyen duong vui long nhap lai: " << endl;
      }else if(soNguyenDuongThuHai > 10000000){
        cout << "so nhap vao lon hon 10 mu 6 vui long nhap lai: " << endl;
      }else{
          break;
      }
	}
  
  
  
 return 0;
}

