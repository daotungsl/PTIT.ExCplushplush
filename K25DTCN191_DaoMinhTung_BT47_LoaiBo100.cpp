#include <iostream>
#include <string>
using namespace std;

void loaiBoXauCon(string s) {
	int dem = 0;
	while(true) {
		int pos = s.find("100");
		if(pos != string::npos) {
			s.erase(pos, 3);
			dem += 3;
			continue;
		}
		break;
	}
	cout << dem << endl;
}

int main() {
	int t;
	cout << "Nhap so luong bo test: ";
	while(true) {
		cin >> t;
		cin.ignore();
		if(t >= 1 && t <= 100) break;
		cout << "Loi: So luong bo test tu 1 den 100. Nhap lai: ";
	}
	
	while(t--) {
		string s;
		cout << "Nhap xau ky tu: ";
		while(true) {
			getline(cin, s);
			if(s.length() >= 1 && s.length() <= 100000) break;
			cout << "Loi: Do dai xau ky tu tu 1 den 100000. Nhap lai: ";
		}
		
		loaiBoXauCon(s);
	}

	return 0;
}
