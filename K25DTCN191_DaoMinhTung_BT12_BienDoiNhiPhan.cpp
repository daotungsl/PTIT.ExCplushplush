#include <iostream>
#include <vector>
using namespace std;

void toggleBits(vector<vector<int>>& matrix, int n, int m) {
    vector<bool> rows(n, false);
    vector<bool> cols(m, false);

    // Bước 1: Đánh dấu hàng và cột có giá trị 1
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] == 1) {
                rows[i] = true;
                cols[j] = true;
            }
        }
    }

    // Bước 2: Cập nhật lại ma trận theo dấu
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (rows[i] || cols[j]) {
                matrix[i][j] = 1;
            }
        }
    }

    // In kết quả
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << matrix[i][j] << " ";
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
        cout << "Loi. So bo test tu 1 den 100. Nhap lai: ";
    }

    while (testCases--) {
        int n, m;
        cout << "Nhap so dong (n): ";
        while (true) {
            cin >> n;
            if (n >= 1 && n <= 100) break;
            cout << "Loi. n tu 1 den 100. Nhap lai: ";
        }

        cout << "Nhap so cot (m): ";
        while (true) {
            cin >> m;
            if (m >= 1 && m <= 100) break;
            cout << "Loi. m tu 1 den 100. Nhap lai: ";
        }

        vector<vector<int>> matrix(n, vector<int>(m));
        cout << "Nhap ma tran nhi phan:\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                while (true) {
                    cin >> matrix[i][j];
                    if (matrix[i][j] == 0 || matrix[i][j] == 1) break;
                    cout << "Chi nhap 0 hoac 1. Nhap lai: ";
                }
            }
        }

        toggleBits(matrix, n, m);
    }

    return 0;
}
