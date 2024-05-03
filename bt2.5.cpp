#include <iostream>
#include <ostream>
#include <math.h>
#include <iomanip> 

using namespace std;

 /*
    Ho va ten: Nguyen Hoang Nam
    MSSV: 20225213
    Ma lop: 738920*/

struct Complex {
    double real;
    double imag;
};

Complex operator + (Complex a, Complex b) {
    Complex c;
    c.real = a.real + b.real;
    c.imag = a.imag + b.imag;
    return c; //Tổng của hai số phức
}

Complex operator - (Complex a, Complex b) {
    Complex c;
    c.real = a.real - b.real;
    c.imag = a.imag - b.imag;
    return c; //Hiệu của 2 số phức
}

Complex operator * (Complex a, Complex b) {
    Complex c;
    //(a+bi)*(c+di) = ac + adi + bci -bd
    c.real = a.real*b.real - a.imag*b.imag;
    c.imag = a.real*b.imag + a.imag*b.real;
    return c; //Tích của hai số phức
}

Complex operator / (Complex a, Complex b) {
    Complex c;
    Complex d; //d là số phức liên hợp của b
    // a/b = (a*d)/(b^2)
    d.real = b.real;
    d.imag = -b.imag;
    c = a*d;
    c.real = c.real / (b.real*b.real + b.imag*b.imag);
    c.imag = c.imag / (b.real*b.real + b.imag*b.imag);
    return c;
}

ostream& operator << (ostream& out, const Complex &a) {
    out << '(' << std::setprecision(2) << a.real << (a.imag >= 0 ? '+' : '-') << std::setprecision(2) << fabs(a.imag) << 'i' << ')';
    return out;
}

int main() {
    double real_a, real_b, img_a, img_b;
    //Nhập vào 2 số phức a, b
    cin >> real_a >> img_a;
    cin >> real_b >> img_b;
    
    Complex a{real_a, img_a};
    Complex b{real_b, img_b};
    
    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl;
    cout << a << " / " << b << " = " << a / b << endl;
    
    return 0;
}