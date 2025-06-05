#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

bool laSoCanBangChanLe(int so){
	stringstream ss;
	ss << so;
	string s = ss.str();
	int soChan = 0, soLe = 0;
	    
	for (int i = 0; i < s.length(); i++) {
		char c = s[i];
		if (c == '0' || c == '2' || c == '4' || c == '6' || c == '8'){
			soChan++;	
		}
		else{
		   soLe++;			
		}

	}
		
		return soChan == soLe;
}

int main(){
	int soChan;
	cout << "nhap mot so chan > 1 va < 7: ";
	cin >> soChan;
	
	while(true){
		if(soChan < 1 || soChan > 7){
			cout << "khong phai so > 1 và < 7 vui long nhap lai: " << endl;
		}else if(soChan%2 != 0){ 
			cout << "khong phai so chan vui long nhap lai: " << endl;
		}else{
			break;
		}
		cin >> soChan;
	}

	int dem = 0;
    int batDau = pow(10, soChan - 1);
    int ketThuc = pow(10, soChan) - 1;
	
	for (int i = batDau; i < ketThuc; i++){
		if (laSoCanBangChanLe(i)) {
            cout << i << " ";
            dem++;
            if (dem % 10 == 0) cout << endl;
        }
	}

	return 0;
}
