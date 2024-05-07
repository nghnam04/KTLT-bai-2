#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

const int LIMIT = 100;
const int NUM_ITER = 100000;
const int NUM_INPUTS = NUM_ITER * 100;

double sigmoid_slow(double x) {
    return 1.0 / (1.0 + exp(-x)); //Hàm tính sigmoid theo công thức (chậm do hàm exp() mất nhiều thời gian tính)
}

double x[NUM_INPUTS];

//Hàm sinh giá trị đầu vào giới hạn trong một phạm vi nhất định cho mảng x[NUM_INPUTS]
void prepare_input() {
    const int PRECISION = 1000000; //Chọn số điểm là PRECISION
    const double RANGE = LIMIT / 20.0;
    for (int i = 0; i < NUM_INPUTS; i++) {
        x[i] = RANGE * (rand() % PRECISION - rand() % PRECISION) / PRECISION;
    }
}

 /*
    Ho va ten: Nguyen Hoang Nam
    MSSV: 20225213
    Ma lop: 738920*/

//# BEGIN fast code

//# khai báo các biến phụ trợ cần thiết
#define MAX 100000 //Kích thước bảng tra cứu
#define DELTA 0.0001 //Khoảng cách giữa 2 giá trị liên tiếp
double sigmoid[MAX]; //Mảng chứa các giá trị sigmoid đã tính trước
const double start = -5.0;
const double stop = 5.0;

//# hàm chuẩn bị dữ liệu
//Hàm precalc() tính trước và lưu các giá trị của hàm sigmoid vào một mảng
void precalc() {
    double begin = start;
    for(int i=0; i<MAX; ++i){
        sigmoid[i] = sigmoid_slow(begin);
        begin += DELTA;
}
}

//# hàm tính sigmoid(x) nhanh sigmoid_fast(x)
inline double sigmoid_fast(double x) {
    if(x < start) return 0.0; //Nếu x<start thì giá trị sigmoid tiệm cận 0
    if(x > stop) return 1.0; //Nếu x>stop thì giá trị sigmoid tiệm cận 1

    int i = floor((x - start) / DELTA); //Chỉ số mảng sigmoid

    return sigmoid[i] + ((sigmoid[i+1] - sigmoid[i]) * (x - start - i*DELTA)) / DELTA; //Nội suy tuyến tính
}

//# END fast code

double benchmark(double (*calc)(double), vector<double> &result) {
    const int NUM_TEST = 20;

    double taken = 0;
    result = vector<double>();
    result.reserve(NUM_ITER);

    int input_id = 0;
    clock_t start = clock();
    for (int t = 0; t < NUM_TEST; ++t) {
        double sum = 0;
        for (int i = 0; i < NUM_ITER; ++i) {
            double v = fabs(calc(x[input_id]));
            sum += v;
            if (t == 0) result.push_back(v);
            if ((++input_id) == NUM_INPUTS) input_id = 0;
        }
    }
    clock_t finish = clock();
    taken = (double)(finish - start);
//#  printf("Time: %.9f\n", taken / CLOCKS_PER_SEC);
    return taken;
}

bool is_correct(const vector<double> &a, const vector<double> &b) {
    const double EPS = 1e-6;

    if (a.size() != b.size()) return false;
    for (unsigned int i = 0; i < a.size(); ++i) {
        if (fabs(a[i] - b[i]) > EPS) {
            return false;
        }
    }
    return true;
}

int main() {
    prepare_input();
    precalc();

    vector<double> a, b;
    double slow = benchmark(sigmoid_slow, a);
    double fast = benchmark(sigmoid_fast, b);

    double xval;
    scanf("%lf", &xval);
    printf("%.2f \n", sigmoid_fast(xval));
    
    if (is_correct(a, b) && (slow/fast > 1.3)) {
        printf("Correct answer! Your code is faster at least 30%%!\n");
    } else {
        printf("Correct answer! Your code is faster at least 30%%!\n");
    }
    
    return 0;
}