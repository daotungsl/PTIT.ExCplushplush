#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
using namespace std;

void nhapDay(vector<int>& a, const string& ten) {
    int n;
    cout << "Nhap so phan tu cua day " << ten << ": ";
    cin >> n;
    cout << "Nhap cac phan tu cua day " << ten << ": ";
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
}

vector<int> hopCua2Day(const vector<int>& a, const vector<int>& b) {
    set<int> tapHop;
    for (int x : a) tapHop.insert(x);
    for (int x : b) tapHop.insert(x);
    return vector<int>(tapHop.begin(), tapHop.end());
}

vector<int> giaoCua2Day(const vector<int>& a, const vector<int>& b) {
    unordered_set<int> tapA(a.begin(), a.end());
    set<int> ketQua;
    for (int x : b) {
        if (tapA.count(x)) {
            ketQua.insert(x); // tránh trùng
        }
    }
    return vector<int>(ketQua.begin(), ketQua.end());
}

void inDay(const vector<int>& a, const string& moTa) {
    cout << moTa << ": ";
    for (int x : a) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    vector<int> A, B;
    nhapDay(A, "A");
    nhapDay(B, "B");

    vector<int> hop = hopCua2Day(A, B);
    vector<int> giao = giaoCua2Day(A, B);

    inDay(hop, "Tap hop (union)");
    inDay(giao, "Tap giao (intersection)");

    return 0;
}
