#include <iostream>
using namespace std;

bool soMayMan (int soKiemTra, int soMayMan){
    int soHangChuc = 0;
    bool ketQua = false;
    
    soHangChuc = soKiemTra % (10*10);
    
   if(soHangChuc == soMayMan){
       ketQua = true;
   }

    return ketQua;
}

int main(){
    int T;
 cout << "nhap so bo test: " << endl;
 cin >> T;
 
 int soKiemTra;
 for (int i = 0; i < T;i++){
       cin >> soKiemTra;
       int ketQua = 0;
       if(soMayMan(soKiemTra,86)){
           ketQua = 1;
       }
       cout <<  ketQua << endl;
 }
 return 0;
}
