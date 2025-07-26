#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <string>
#include <cctype>
using namespace std;

string chuanHoa(string tu) {
    string res;
    for (char c : tu) {
        if (isalnum(c)) res += tolower(c); // chỉ lấy chữ và số, chuyển thường
    }
    return res;
}

set<string> docVaLayTu(const string& tenFile) {
    ifstream fin(tenFile);
    set<string> tap;
    string dong;
    while (getline(fin, dong)) {
        stringstream ss(dong);
        string tu;
        while (ss >> tu) {
            tu = chuanHoa(tu);
            if (!tu.empty()) tap.insert(tu);
        }
    }
    return tap;
}

int main() {
    set<string> tap1 = docVaLayTu("DATA1.in");
    set<string> tap2 = docVaLayTu("DATA2.in");

    // Hợp
    set<string> hop = tap1;
    for (const auto& tu : tap2) {
        hop.insert(tu);
    }

    // Giao
    set<string> giao;
    for (const auto& tu : tap1) {
        if (tap2.count(tu)) {
            giao.insert(tu);
        }
    }

    cout << "Hop cua 2 tep:\n";
    for (const string& tu : hop) cout << tu << " ";
    cout << "\n\n";

    cout << "Giao cua 2 tep:\n";
    for (const string& tu : giao) cout << tu << " ";
    cout << "\n";

    return 0;
}
