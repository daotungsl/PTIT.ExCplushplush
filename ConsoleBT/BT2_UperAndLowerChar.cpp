//#include "BT2_UperAndLowerChar.h"
#include <iostream>

using namespace std;


void BT2_UperAndLowerChar()
{
	int T;
	cout << "nhap so bo test: ";
	cin >> T;
	char c;

    for (int i = 0; i < T; i++) {
        cin >> c;
        if (c >= 'A' && c <= 'Z') {
            cout << (char)(c + 32) << endl; // chuyển chữ hoa thành thường
        }
        else if (c >= 'a' && c <= 'z') {
            cout << (char)(c - 32) << endl; // chuyển chữ thường thành hoa
        }
        else {
            cout << c << endl; // nếu không phải chữ cái thì in nguyên
        }
    }
}
