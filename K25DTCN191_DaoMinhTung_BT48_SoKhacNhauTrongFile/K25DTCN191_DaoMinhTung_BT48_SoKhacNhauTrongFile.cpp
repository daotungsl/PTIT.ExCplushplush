#include <iostream>
#include <fstream>
#include <map>
using namespace std;

int main() {
    ifstream fin("DATA.in");
    if (!fin) {
        cerr << "Khong the mo file DATA.in de doc!" << endl;
        return 1;
    }

    map<int, int> demSo;

    int x;
    while (fin >> x) {
        if (x > 0 && x <= 1000)
            demSo[x]++;
    }

    for (auto& [so, tanSuat] : demSo) {
        cout << so << " " << tanSuat << endl;
    }

    fin.close();
    return 0;
}
