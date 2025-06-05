#include <iostream>

using namespace std;


int main()
{
	int T;
	cout << "nhap so bo test: ";
	cin >> T;
	char c;

    for (int i = 0; i < T; i++) {
        cin >> c;
        if (c >= 'A' && c <= 'Z') {
            cout << (char)(c + 32) << endl; 
        }
        else if (c >= 'a' && c <= 'z') {
            cout << (char)(c - 32) << endl; 
        }
        else {
            cout << "khong phai chu cai tu A->Z hoac a->z" << endl;
        }
    }
    return 0;
}
