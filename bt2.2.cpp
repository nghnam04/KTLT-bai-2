#include <stdio.h>

void rotate(int &x, int &y, int &z) {
 /*
    Ho va ten: Nguyen Hoang Nam
    MSSV: 20225213
    Ma lop: 738920*/
    //Hoán vị vòng tròn x, y, z thành y, z, x
    int temp=x;
    x=y;
    y=z;
    z=temp;
}

int main() {
    int x, y, z;
    
    //# Nhập 3 số nguyên
    scanf("%d %d %d", &x, &y, &z);
    
    printf("Before: %d, %d, %d\n", x, y, z); //Giá trị x, y, z trước khi hoán vị
    rotate(x, y, z);
    printf("After: %d, %d, %d\n", x, y, z); //Giá trị x, y, z sau hoán vị
    
    return 0;
}