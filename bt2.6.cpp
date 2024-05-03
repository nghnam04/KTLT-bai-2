#include <stdio.h>

  /*
    Ho va ten: Nguyen Hoang Nam
    MSSV: 20225213
    Ma lop: 738920*/

void print(int n) {
    printf("n=%d\n", n);
}

int mul3plus1(int n) {
    return n * 3 + 1; 
}

int div2(int n) {
    return n / 2; 
}

// khai báo các tham số cho các con trỏ hàm odd, even và output
void simulate(int n, int (*odd)(int), int (*even)(int), void (*output)(int))  {
    (*output)(n);
    if (n == 1) return; //n=1 thì dừng đệ quy
    if (n % 2 == 0) {
        n = (*even)(n); //n chẵn thì chia 2
    } else {
        n = (*odd)(n); //n lẻ thì nhân 3 cộng 1
    }
    simulate(n, odd, even, output);
}

int main() {
    //Gán 2 con trỏ hàm odd và even là NULL
    int (*odd)(int) = NULL;
    int (*even)(int) = NULL;
    odd = mul3plus1;
    even = div2;


    int n;
    scanf("%d", &n); //Nhập n từ bàn phím
    simulate(n, odd, even, print);

    return 0;
}