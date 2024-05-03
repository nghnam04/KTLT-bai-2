#include <stdio.h>
#include <math.h>

float get_hypotenuse(float x, float y) {
    /*
    Ho va ten: Nguyen Hoang Nam
    MSSV: 20225213
    Ma lop: 738920*/
    //Trả về giá trị cạnh huyền bằng căn bậc hai tổng bình phương hai cạnh
    return sqrt(x*x + y*y); 
}

int main(){
    float x, y;
    scanf("%f%f", &x, &y); //Nhập vào từ bàn phím x và y   

    float z = get_hypotenuse(x, y); //Tính cạnh huyền z dựa trên 2 cạnh góc vuông x, y
    printf("z = %.2f\n", z);
    
    return 0;
}