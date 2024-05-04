#include <iostream>
#include <vector>

using namespace std;

// Hàm nhân hai đa thức
vector<int> multiplyPolynomials(const vector<int>& a, const vector<int>& b) {
    int n = a.size();
    int m = b.size();
    vector<int> product(n + m - 1, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            product[i + j] += a[i] * b[j];
        }
    }

    return product;
}

// Hàm để tính XOR của tất cả các hệ số trong đa thức
int xorOfCoefficients(const vector<int>& coeffs) {
    int result = 0;
    for (int coeff : coeffs) {
        result ^= coeff;
    }
    return result;
}

int main() {
    int n, m;
    // Đọc bậc và hệ số của đa thức A(x)
    cin >> n;
    vector<int> A(n + 1);
    for (int i = 0; i <= n; ++i) {
        cin >> A[i];
    }

    // Đọc bậc và hệ số của đa thức B(x)
    cin >> m;
    vector<int> B(m + 1);
    for (int i = 0; i <= m; ++i) {
        cin >> B[i];
    }

    // Nhân hai đa thức
    vector<int> C = multiplyPolynomials(A, B);

    // Tính XOR của các hệ số trong đa thức kết quả
    int result = xorOfCoefficients(C);
    cout << result << endl;

    return 0;
}
