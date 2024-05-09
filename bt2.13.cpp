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
void add(char res[], char *num1, char *num2){
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
        } 
        else {
            temp1 = temp1 + 10;
            res[i] = temp1 - temp2 - c + 48;
            c = 1; //Số bị trừ nhỏ hơn số trừ thì biến nhớ bằng 1
        }
    }
}

//Hàm nhân hai số nguyên lớn
void multi(char res[], char *num1, char *num2){
    for(int i=0; i<101; i++) res[i] = '0'; //Xóa mảng res

    for(int i=100; i>=0; i--){
        char temp[101];

        int k;
        for(k = 0; k < i; k++)
            temp[100-k] = '0'; //Thêm các số 0 vào cuối mảng

        int c = 0, sum = 0;
        for(int j=100; j>=0; j--){
            sum = ((int)num1[i] - 48) * ((int)num2[j] - 48) + c;
            temp[k] = (sum % 10) + 48; //Giá trị ô tương ứng là giá trị hàng đơn vị kết quả nhân
            c = sum / 10; //Biến nhớ là kết giá trị số ở hàng lớn nhất
            k--; 
            if(k < 0) break;
        }

        add(res,temp,res);
    }
}

//Hàm kiếm tra xem num1 có lớn hơn num2 hay không
bool check(char *num1, char *num2){
    int start1, start2;
    for(start1 = 0; start1 < 101; start1++){
        if(num1[start1] != '0') break; //Tìm đến vị trí của hàng lớn nhất số nguyên lớn lưu trong mảng num1
    }

    for(start2 = 0; start2 < 101; start2++){
        if(num2[start2] != '0') break; //Tìm đến vị trí của hàng lớn nhất số nguyên lớn lưu trong mảng num2
    }

    if(start1 > start2) return false; //Vị trí của chữ số ở hàng lớn nhất trong mảng 1 lớn hơn so với mảng 2 thì num1 < num2
    else if(start1 < start2) return true; //Ngược lại num1 > num2
    else { //rường hợp num1 và num2 có cùng số chữ số
        int t = start1;
        while(t < 101){
            if(num1[t] < num2[t]) return false;
            else if (num1[t] > num2[t]) return true;
            else {
                t++;
            }
        }
    }

    return true;
}

//Đa năng hóa toán tử +
bigNum operator + (bigNum num1, bigNum num2){
    bigNum res;

    if(num1.sign == '1' && num2.sign == '1'){//Hai số âm
        res.sign = '1';
        add(res.num,num1.num,num2.num);
        return res;
    } 
    else if(num1.sign == '1' && num2.sign == '0'){//Num1<0, num2>0
        if(check(num1.num,num2.num)){
            res.sign = '1';
            sub(res.num,num1.num,num2.num);
            return res;
        } else {
            res.sign = '0';
            sub(res.num,num2.num,num1.num);
            return res;
        }
    } 
    else if(num1.sign == '0' && num2.sign == '1'){//num1>0, num2<0
        if(check(num1.num,num2.num)){
            res.sign = '0';
            sub(res.num,num1.num,num2.num);
            return res;
        } else {
            res.sign = '1';
            sub(res.num,num2.num,num1.num);
            return res;
        }
    } 
    else {//Hai số dương
        res.sign = '0';
        add(res.num,num1.num,num2.num);
        return res;
    }
}

//Đa năng hóa toán tử -
bigNum operator - (bigNum num1, bigNum num2){
    bigNum res;

    if(num1.sign == '1' && num2.sign == '0'){ //Num1<0, num2>0
        num2.sign = '1';
        res = num1 + num2;
        return res;
    }
     else if(num1.sign == '1' && num2.sign == '1'){//Hai số âm
        num2.sign = '0';
        res = num1 + num2;
        return res;
    }
     else if(num1.sign == '0' && num2.sign == '1'){//num1>0, num2<0
        num2.sign = '0';
        res = num1 + num2;
        return res;
    } 
    else {//Hai số dương
        num2.sign = '1';
        res = num1 + num2;
        return res;
    }
}

//Đa năng hóa toán tử *
bigNum operator * (bigNum num1, bigNum num2){
    bigNum res;

    if(num1.sign == '1' && num2.sign == '1'){//Hai số âm
        res.sign = '1';
        multi(res.num,num1.num,num2.num);
        return res;
    } 
    else if(num1.sign == '1' && num2.sign == '0'){//num1<0, num2>0
        res.sign = '0';
        multi(res.num,num1.num,num2.num);
        return res;
    } 
    else if(num1.sign == '0' && num2.sign == '1'){//num1>0, num2<0
        res.sign = '0';
        multi(res.num,num1.num,num2.num);
        return res;
    } 
    else {//Hai số dương
        res.sign = '1';
        multi(res.num,num1.num,num2.num);
        return res;
    }
}

//Hàm in ra mảng số nguyên lớn
void printBigNumber(bigNum number){
    cout << number.sign;
    int i;
    for(i=0; i<101; i++)
        if(number.num[i] != '0') break; //Bỏ qua các số 0 từ đầu mảng cho tới khi gặp số khác 0 đầu tiên

    for(int j = i; j<101; j++)
        cout << number.num[j]; //In ra các số khác 0 còn lại cho tới hết mảng
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