#include <iostream>
#include <string>
using namespace std;

struct bigNum {
    char sign;
    char num[101]{};

    bigNum(string s = "+0") {
        sign = (s[0] == '-' ? '0' : '1');
        fill(begin(num), end(num), '0');
        for (int i = 1, j = 100; i < s.size(); ++i, --j) {
            num[j] = s[i];
        }
    }

    void print() const {
        cout << (sign == '1' ? '+' : '-');
        bool lead = true;
        for (int i = 0; i < 101; ++i) {
            if (num[i] != '0' || !lead) {
                cout << num[i];
                lead = false;
            }
        }
        if (lead) cout << '0'; // Print zero if all digits are zero
    }

    friend bigNum operator+(const bigNum& a, const bigNum& b);
    friend bigNum operator-(const bigNum& a, const bigNum& b);
    friend bigNum operator*(const bigNum& a, const bigNum& b);
};

bigNum operator+(const bigNum& a, const bigNum& b) {
    bigNum res;
    int carry = 0;
    for (int i = 100; i >= 0; --i) {
        int n1 = a.num[i] - '0';
        int n2 = b.num[i] - '0';
        int sum = n1 + n2 + carry;
        res.num[i] = (sum % 10) + '0';
        carry = sum / 10;
    }
    res.sign = (carry == 0 ? '1' : '1'); // Simplification assumes correct input
    return res;
}

bigNum operator-(const bigNum& a, const bigNum& b) {
    bigNum res, b_neg = b;
    b_neg.sign = (b.sign == '1' ? '0' : '1'); // Negate b
    return a + b_neg;
}

bigNum operator*(const bigNum& a, const bigNum& b) {
    bigNum res;
    for (int i = 100; i >= 0; --i) {
        if (a.num[i] == '0') continue;
        int carry = 0, n1 = a.num[i] - '0';
        for (int j = 100, k = 100 - (100 - i); j >= 0 && k >= 0; --j, --k) {
            int n2 = b.num[j] - '0';
            int prod = n1 * n2 + (res.num[k] - '0') + carry;
            res.num[k] = (prod % 10) + '0';
            carry = prod / 10;
        }
    }
    res.sign = (a.sign == b.sign ? '1' : '0');
    return res;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    bigNum num1(s1), num2(s2), so3("+3"), so4("+4");

    bigNum result = num1 * num2 - so3 * num1 + so4 * num2;
    result.print();
}
