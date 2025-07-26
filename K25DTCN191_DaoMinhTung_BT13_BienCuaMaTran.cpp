#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void printMatrixBorder(const vector<vector<int>>& matrix, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1)
                cout << setw(4) << matrix[i][j];
            else
                cout << setw(4) << " ";
        }
        cout << endl;
    }
}

int main() {
    int testCases;
    cout << "Nhap so luong bo test: ";
    while (true) {
        cin >> testCases;
        if (testCases >= 1 && testCases <= 100) break;
        cout << "Loi: t phai tu 1 den 100. Nhap lai: ";
    }

    while (testCases--) {
        int n;
        cout << "Nhap kich thuoc ma tran vuong n x n: ";
        while (true) {
            cin >> n;
            if (n >= 1 && n <= 100) break;
            cout << "Loi: n phai tu 1 den 100. Nhap lai: ";
        }

        vector<vector<int>> matrix(n, vector<int>(n));
        cout << "Nhap ma tran:\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                while (true) {
                    cin >> matrix[i][j];
                    if (matrix[i][j] >= 1 && matrix[i][j] <= 150) break;
                    cout << "Gia tri tu 1 den 150. Nhap lai: ";
                }
            }
        }

        cout << "Phan tu tren bien cua ma tran:\n";
        printMatrixBorder(matrix, n);
    }

    return 0;
}
