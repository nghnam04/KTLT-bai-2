#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

 /*
    Ho va ten: Nguyen Hoang Nam
    MSSV: 20225213
    Ma lop: 738920*/

int main() {
    int val1, val2;
    cin >> val1 >> val2; //Nhập vào giá trị val1, val2
    vector< vector<int> > a = {
        {1, 3, 7},
        {2, 3, 4, val1},
        {9, 8, 15},
        {10, val2},
    };

    //# sắp xếp các vector trong a theo tổng các phần tử giảm dần
    sort(a.begin(), a.end(), [](vector<int> v1, vector<int> v2){
        int s1=0; 
        for(int i= 0; i < v1.size(); i++){
            s1 += v1[i];
        }
         int s2=0; 
        for(int j= 0; j < v2.size(); j++){
            s2 += v2[j];
        }
        return s1>s2;
    });

    for (const auto &v : a) {
        for (int it : v) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}