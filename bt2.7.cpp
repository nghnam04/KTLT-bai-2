#include <iostream>
using namespace std;

 /*
    Ho va ten: Nguyen Hoang Nam
    MSSV: 20225213
    Ma lop: 738920*/

template <typename T>
//# viết hàm arr_sum
T arr_sum (T a[], int sizea, T b[], int sizeb){
T sum;
for(int i=0; i<sizea; i++) sum+=a[i];
for (int j=0; j<sizeb; j++) sum+=b[j];
return sum; //Sum là biến lưu trữ tổng các phần tử trong mảng
}

int main() {
    int val;
    cin >> val;
    
    {
        int a[] = {3, 2, 0, val};
        int b[] = {5, 6, 1, 2, 7};
        cout << arr_sum(a, 4, b, 5) << endl;
    }
    {
        double a[] = {3.0, 2, 0, val * 1.0};
        double b[] = {5, 6.1, 1, 2.3, 7};
        cout << arr_sum(a, 4, b, 5) << endl;
    }

    return 0;
}