#include <iostream>

using namespace std;

int main()
{
	int T;
	cout << "nhap so de tinh tong giai thua: ";
	cin >> T;
	int KQ;
	for	(int i = 1; i <= T; i++){
				
		int tich = 1;
		
		for (int j = 1; j <= i;j++){
			tich = tich*j;
		};
		
		KQ += tich;
	};
	cout << "tong giai thua tu 1! den "<< T << "! la: " << KQ << endl;

	
	return 0;
}
