#include<bits/stdc++.h>
using namespace std;

struct element {
    int key;
    int value;
};

vector<element> lst;

//Nhập vào các elements của list
void input(){
    int temp1, temp2;
    while(cin >> temp1 && cin >> temp2){
        element temp;
        temp.key = temp1;
        temp.value = temp2;

        lst.push_back(temp);
    }
}

//In ra list 
void print(){
    for(int i=0; i<lst.size(); i++){
        cout << lst[i].key << " " << lst[i].value << endl;
    }
}

int main(){
    input();
    /*Sắp xếp các element trong list theo thứ tự giảm dần value
    Nếu value bằng nhau thì sắp xếp theo thứ tự giảm dân key*/
    sort(lst.begin(), lst.end(),[] (element a, element b){
        if(a.value > b.value) return true;
        else if (a.value < b.value) return false;
        else {
            return a.key >= b.key;
        }
    });
    print();
    return 0;
}