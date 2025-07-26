#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void nhapMaTran(vector<vector<int>>& mat, int n) {
    cout << "Nhap cac phan tu cua ma tran " << n << "x" << n << ":\n";
    for (int i = 0; i < n; ++i) {
        mat[i].resize(n);
        for (int j = 0; j < n; ++j) {
            cin >> mat[i][j];
        }
    }
}

vector<vector<int>> xoayMaTran90(const vector<vector<int>>& mat, int n) {
    vector<vector<int>> rotated(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            rotated[j][n - 1 - i] = mat[i][j];
        }
    }
    return rotated;
}

void inMaTran(const vector<vector<int>>& mat, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw(4) << mat[i][j];
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Nhap kich thuoc ma tran vuong (n x n): ";
    while (true) {
        cin >> n;
        if (n >= 1 && n <= 100) break;
        cout << "Loi: 1 <= n <= 100. Nhap lai: ";
    }

    vector<vector<int>> mat(n);
    nhapMaTran(mat, n);

    cout << "Ma tran ban dau:\n";
    inMaTran(mat, n);

    vector<vector<int>> quay = xoayMaTran90(mat, n);

    cout << "Ma tran sau khi xoay 90 do:\n";
    inMaTran(quay, n);

    return 0;
}
