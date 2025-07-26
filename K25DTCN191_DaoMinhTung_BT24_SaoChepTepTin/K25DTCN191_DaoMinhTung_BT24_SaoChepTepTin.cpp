#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // Bước 1: Tạo file PTIT.in và ghi nội dung
    ofstream fout("PTIT.in");
    if (!fout.is_open()) {
        cerr << "Loi: Khong mo duoc file PTIT.in de ghi!" << endl;
        return 1;
    }
    fout << "Ngon ngu lap trinh C++";
    fout.close();

    // Bước 2: Đọc từ PTIT.in và ghi sang PTIT.out
    ifstream fin("PTIT.in");
    ofstream fout2("PTIT.out");

    if (!fin.is_open() || !fout2.is_open()) {
        cerr << "Loi: Khong mo duoc file de doc hoac ghi!" << endl;
        return 1;
    }

    string line;
    while (getline(fin, line)) {
        fout2 << line << endl;
    }

    fin.close();
    fout2.close();

    cout << "Da sao chep noi dung tu PTIT.in sang PTIT.out thanh cong.\n";
    return 0;
}
