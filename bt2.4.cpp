#include <stdio.h>

int cube(int x) {
    //# trả về lập phương của x
  /*
    Ho va ten: Nguyen Hoang Nam
    MSSV: 20225213
    Ma lop: 738920*/
    return x*x*x; //Trả về giá trị x^3
}

//# viết hàm tính lập phương của một số kiểu double
double cube(double x){
    return x*x*x;
}

int main() {
    int n;
    double f;
    scanf("%d %lf", &n, &f); //Nhập vào ố nguyên n và số thực f
    //In ra giá trị của lập phương n và f
    printf("Int: %d\n", cube(n));
    printf("Double: %.2lf\n", cube(f));
    
    return 0;
}