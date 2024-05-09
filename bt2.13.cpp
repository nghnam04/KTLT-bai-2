#include<iostream>
#include<string>
using namespace std;

/*
    Ho va ten: Nguyen Hoang Nam
    MSSV: 20225213
    Ma lop: 738920*/
    
struct bigNum {
    char sign;
    char num[101];
};

//Hàm nhập dữ liệu cho mảng chứa số nguyên lớn
void input(bigNum &num1, bigNum &num2){
    string temp;
    cin >> temp;
    num1.sign = temp[0];
    int lengths1 = temp.length() - 1;
    for(int i=0; i<lengths1; i++){
        num1.num[100-lengths1+i+1] = temp[i+1]; //Nhập số nguyên lớn đó vào từng ô ở cuối mảng num1
    }
    for(int i=0; i<100-lengths1+1; i++) num1.num[i] = '0'; //Các ô từ đầu đến trước số nguyên lớn gán bằng 0

    cin >> temp;
    num2.sign = temp[0];
    int lengths2 = temp.length() - 1;
    for(int i=0; i<lengths2; i++){
        num2.num[100-lengths2+i+1] = temp[i+1]; //Nhập số nguyên lớn đó vào từng ô ở cuối mảng num2
    }
    for(int i=0; i<100-lengths2+1; i++) num2.num[i] = '0'; //Các ô từ đầu đến trước số nguyên lớn gán bằng 0
}

//Hàm cộng hai số nguyên lớn
void add(char res[], char* num1, char* num2){
    int c = 0;

    for(int i=100; i>=0; i--){
        int temp = (int)num1[i] - 48 + (int)num2[i] - 48 + c; //Cộng hai giá trị tại 2 hàng tương ứng
        c = temp / 10; //c là biến nhớ
        res[i] = temp % 10 + 48; //Chuyển số ở ô của mảng thành kiểu char
    }
}

//hàm trừ hai số nguyên lớn
void sub(char res[], char* num1, char* num2){
    int c = 0;

    for(int i=100; i>=0; i--){
        int temp1 = (int)num1[i] - 48;
        int temp2 = (int)num2[i] - 48;

        if(temp1 >= temp2 + c){
            res[i] = temp1 - temp2 - c + 48;
            c = 0; //Số bị trừ lớn hơn số trừ thì biến nhớ bằng 0
        } else {
            temp1 = temp1 + 10;
            res[i] = temp1 - temp2 - c + 48;
            c = 1; //Số bị trừ nhỏ hơn số trừ thì biến nhớ bằng 1
        }
    }
}

//Hàm nhân hai số nguyên lớn
void multi(char res[], char *num1, char *num2){
    // clear array res
    for(int i=0; i<101; i++) res[i] = '0';

    for(int i=100; i>=0; i--){
        // init 1 array temp
        char tmp[101];

        // add i number 0 to last array
        int k;
        for(k = 0; k < i; k++)
            tmp[100-k] = '0';

        int c = 0, sum = 0;
        for(int j=100; j>=0; j--){
            sum = ((int)num1[i] - 48) * ((int)num2[j] - 48) + c;
            tmp[k] = (sum % 10) + 48;
            c = sum / 10;
            k--; if(k < 0) break;
        }

        add(res,tmp,res);
    }
}

// check number1 >= number2
bool check(char *num1, char *num2){
    int foo1, foo2;
    for(foo1 = 0; foo1 < 101; foo1++){
        if(num1[foo1] != '0') break;
    }

    for(foo2 = 0; foo2 < 101; foo2++){
        if(num2[foo2] != '0') break;
    }

    if(foo1 > foo2) return false;
    else if(foo1 < foo2) return true;
    else { // foo1 == foo2
        int foo = foo1;
        while(foo < 101){
            if(num1[foo] < num2[foo]) return false;
            else if (num1[foo] > num2[foo]) return true;
            else {
                foo++;
            }
        }
    }

    return true;
}

// overloading operator "+"
bigNum operator + (bigNum num1, bigNum num2){
    bigNum res;

    if(num1.sign == '1' && num2.sign == '1'){
        res.sign = '1';
        add(res.num,num1.num,num2.num);
        return res;
    } else if(num1.sign == '1' && num2.sign == '0'){
        if(check(num1.num,num2.num)){
            res.sign = '1';
            sub(res.num,num1.num,num2.num);
            return res;
        } else {
            res.sign = '0';
            sub(res.num,num2.num,num1.num);
            return res;
        }
    } else if(num1.sign == '0' && num2.sign == '1'){
        if(check(num1.num,num2.num)){
            res.sign = '0';
            sub(res.num,num1.num,num2.num);
            return res;
        } else {
            res.sign = '1';
            sub(res.num,num2.num,num1.num);
            return res;
        }
    } else {
        res.sign = '0';
        add(res.num,num1.num,num2.num);
        return res;
    }
}

bigNum operator - (bigNum num1, bigNum num2){
    bigNum res;

    if(num1.sign == '1' && num2.sign == '0'){
        num2.sign = '1';
        res = num1 + num2;
        return res;
    } else if(num1.sign == '1' && num2.sign == '1'){
        num2.sign = '0';
        res = num1 + num2;
        return res;
    } else if(num1.sign == '0' && num2.sign == '1'){
        num2.sign = '0';
        res = num1 + num2;
        return res;
    } else {
        num2.sign = '1';
        res = num1 + num2;
        return res;
    }
}

bigNum operator * (bigNum num1, bigNum num2){
    bigNum res;

    if(num1.sign == '1' && num2.sign == '1'){
        res.sign = '1';
        multi(res.num,num1.num,num2.num);
        return res;
    } else if(num1.sign == '1' && num2.sign == '0'){
        res.sign = '0';
        multi(res.num,num1.num,num2.num);
        return res;
    } else if(num1.sign == '0' && num2.sign == '1'){
        res.sign = '0';
        multi(res.num,num1.num,num2.num);
        return res;
    } else {
        res.sign = '1';
        multi(res.num,num1.num,num2.num);
        return res;
    }
}

// print bignumber
void printBigNumber(bigNum number){
    cout << number.sign;
    int start;
    for(start=0; start<101; start++)
        if(number.num[start] != '0') break;

    for(int i = start; i<101; i++)
        cout << number.num[i];
}

int main(){
    bigNum num1, num2;
    input(num1,num2);

    bigNum so3, so4;
    so3.sign = '1', so4.sign = '1';
    for(int i=0; i<100; i++){
        so3.num[i] = '0';
        so4.num[i] = '0';
    }
    so3.num[100] = 3 + 48;
    so4.num[100] = 4 + 48;

    bigNum res = num1*num2 - so3 * num1 + so4 * num2;

    printBigNumber(res);
}