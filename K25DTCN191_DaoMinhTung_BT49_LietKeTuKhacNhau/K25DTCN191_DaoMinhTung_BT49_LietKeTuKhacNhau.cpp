#include <iostream>
#include <fstream>
#include <set>
#include <sstream>
#include <cctype>
using namespace std;

string chuanHoa(string s) {
    for (char& c : s) c = tolower(c);
    return s;
}

int main() {
    ifstream fin("VANBAN.in");
    if (!fin) {
        cerr << "Khong the mo file VANBAN.in!" << endl;
        return 1;
    }

    set<string> tapTu;
    string dong;
    while (getline(fin, dong)) {
        stringstream ss(dong);
        string tu;
        while (ss >> tu) {
            tapTu.insert(chuanHoa(tu));
        }
    }

    for (const auto& tu : tapTu) {
        cout << tu << endl;
    }

    return 0;
}
